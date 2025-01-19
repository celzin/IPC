#include "includes/fila.h"

FilaPrioridade *criar_fila()
{
    FilaPrioridade *fila = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));
    if (fila)
    {
        fila->frente = NULL;
    }
    return fila;
}

void adicionar_cliente(FilaPrioridade *fila, Cliente *cliente)
{
    NodaFila *novo_nodo = (NodaFila *)malloc(sizeof(NodaFila));
    if (!novo_nodo)
        return;

    novo_nodo->cliente = cliente;
    novo_nodo->proximo = NULL;

    if (!fila->frente || cliente->prioridade < fila->frente->cliente->prioridade)
    {
        novo_nodo->proximo = fila->frente;
        fila->frente = novo_nodo;
        return;
    }

    NodaFila *atual = fila->frente;
    while (atual->proximo && cliente->prioridade >= atual->proximo->cliente->prioridade)
    {
        atual = atual->proximo;
    }

    novo_nodo->proximo = atual->proximo;
    atual->proximo = novo_nodo;
}

Cliente *atender_cliente(FilaPrioridade *fila)
{
    if (!fila->frente)
        return NULL;

    NodaFila *temp = fila->frente;
    Cliente *cliente_atendido = temp->cliente;
    fila->frente = fila->frente->proximo;
    free(temp);
    return cliente_atendido;
}

void imprimir_fila(FilaPrioridade *fila)
{
    NodaFila *atual = fila->frente;
    while (atual)
    {
        printf("Cliente: %s | Prioridade: %d\n", atual->cliente->nome, atual->cliente->prioridade);
        atual = atual->proximo;
    }
}