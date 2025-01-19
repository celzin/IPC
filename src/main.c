#include "includes/supermercado.h"

int main()
{
    Supermercado *mercado = criar_supermercado();

    int opcao;
    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Atender Cliente\n");
        printf("3. Abrir/Fechar Caixa\n");
        printf("4. Imprimir Lista de Clientes em Espera\n");
        printf("5. Imprimir Status dos Caixas\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrar_cliente(mercado);
            break;
        case 2:
            atender_cliente_supermercado(mercado);
            break;
        case 3:
            abrir_fechar_caixa(mercado);
            break;
        case 4:
            imprimir_clientes_espera(mercado);
            break;
        case 5:
            imprimir_status(mercado);
            break;
        case 0:
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    destruir_supermercado(mercado);
    return 0;
}