#include "includes/caixa.h"

Caixa *criar_caixa(int id)
{
    Caixa *novo_caixa = (Caixa *)malloc(sizeof(Caixa));
    if (novo_caixa)
    {
        novo_caixa->id = id;
        novo_caixa->estado = 1;
        novo_caixa->fila = criar_fila();
    }
    return novo_caixa;
}
