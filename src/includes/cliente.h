#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_NOME 100
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[MAX_NOME];
    int cpf;
    int prioridade;
    int itens;
} Cliente;

Cliente *criar_cliente(const char *nome, int cpf, int prioridade, int itens);

#endif