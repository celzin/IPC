#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 100
#define MAX_CPF 12 // 11 dígitos + '\0'

typedef struct
{
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    int prioridade;
    int itens;
} Cliente;

Cliente *criar_cliente(const char *nome, const char *cpf, int prioridade, int itens);
int validar_nome(const char *nome);
int validar_cpf(const char *cpf);

#endif