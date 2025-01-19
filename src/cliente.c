#include "includes/cliente.h"

Cliente *criar_cliente(const char *nome, int cpf, int prioridade, int itens)
{
    Cliente *novo_cliente = (Cliente *)malloc(sizeof(Cliente));
    if (novo_cliente)
    {
        strncpy(novo_cliente->nome, nome, MAX_NOME);
        novo_cliente->cpf = cpf;
        novo_cliente->prioridade = prioridade;
        novo_cliente->itens = itens;
    }
    return novo_cliente;
}
