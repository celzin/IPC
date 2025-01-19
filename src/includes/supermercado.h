#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include "caixa.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    Caixa *caixas[5];
} Supermercado;

Supermercado *criar_supermercado();

void cadastrar_cliente(Supermercado *mercado);
void atender_cliente_supermercado(Supermercado *mercado);
void abrir_fechar_caixa(Supermercado *mercado);
void imprimir_clientes_espera(Supermercado *mercado);
void imprimir_status(Supermercado *mercado);
void destruir_supermercado(Supermercado *mercado);

#endif
