#ifndef FILA_H
#define FILA_H

#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct NodaFila
{
    Cliente *cliente;
    struct NodaFila *proximo;
} NodaFila;

typedef struct
{
    NodaFila *frente;
} FilaPrioridade;

FilaPrioridade *criar_fila();
void adicionar_cliente(FilaPrioridade *fila, Cliente *cliente);
Cliente *atender_cliente(FilaPrioridade *fila); // Retorna Cliente*
void imprimir_fila(FilaPrioridade *fila);

#endif
