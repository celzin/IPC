#ifndef CAIXA_H
#define CAIXA_H

#include "fila.h"
#include <stdlib.h>

typedef struct
{
    int id;
    int estado;
    FilaPrioridade *fila;
} Caixa;

Caixa *criar_caixa(int id);

#endif