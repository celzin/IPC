#include "includes/cliente.h"

int validar_nome(const char *nome)
{
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (!isalpha(nome[i]) && !isspace(nome[i]))
        {
            return 0;
        }
    }
    return 1;
}

int validar_cpf(const char *cpf)
{
    if (strlen(cpf) != 11)
        return 0;

    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
            return 0;
    }

    return 1; // CPF válido
}

Cliente *criar_cliente(const char *nome, const char *cpf, int prioridade, int itens)
{
    Cliente *novo_cliente = (Cliente *)malloc(sizeof(Cliente));
    if (novo_cliente)
    {
        strncpy(novo_cliente->nome, nome, MAX_NOME);
        strncpy(novo_cliente->cpf, cpf, MAX_CPF);
        novo_cliente->prioridade = prioridade;
        novo_cliente->itens = itens;
    }
    return novo_cliente;
}
