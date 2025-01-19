#include "includes/supermercado.h"

Supermercado *criar_supermercado()
{
    Supermercado *mercado = (Supermercado *)malloc(sizeof(Supermercado));
    if (mercado)
    {
        for (int i = 0; i < 5; i++)
        {
            mercado->caixas[i] = criar_caixa(i + 1);
        }
    }
    return mercado;
}

void cadastrar_cliente(Supermercado *mercado)
{
    char nome[MAX_NOME];
    int cpf, prioridade, itens, id_caixa;

    printf("Nome: ");
    getchar();
    fgets(nome, MAX_NOME, stdin);
    printf("CPF: ");
    scanf("%d", &cpf);
    printf("Prioridade (1-Alta, 2-Média, 3-Baixa): ");
    scanf("%d", &prioridade);
    printf("Itens: ");
    scanf("%d", &itens);
    printf("Escolha o caixa (1-5): ");
    scanf("%d", &id_caixa);

    Cliente *novo_cliente = criar_cliente(nome, cpf, prioridade, itens);
    adicionar_cliente(mercado->caixas[id_caixa - 1]->fila, novo_cliente);
}

void atender_cliente_supermercado(Supermercado *mercado)
{
    int id_caixa;
    printf("Escolha o caixa (1-5): ");
    scanf("%d", &id_caixa);

    if (id_caixa < 1 || id_caixa > 5)
    {
        printf("Caixa inválido.\n");
        return;
    }

    Cliente *cliente_atendido = atender_cliente(mercado->caixas[id_caixa - 1]->fila);
    if (cliente_atendido)
    {
        printf("Atendendo cliente: %s\n", cliente_atendido->nome);
        free(cliente_atendido);
    }
    else
    {
        printf("Nenhum cliente na fila do caixa %d.\n", id_caixa);
    }
}

void abrir_fechar_caixa(Supermercado *mercado)
{
    int id_caixa;
    printf("Escolha o caixa (1-5) para abrir ou fechar: ");
    scanf("%d", &id_caixa);

    if (id_caixa < 1 || id_caixa > 5)
    {
        printf("Caixa inválido.\n");
        return;
    }

    Caixa *caixa = mercado->caixas[id_caixa - 1];
    if (caixa->estado)
    {
        printf("Fechando caixa %d...\n", id_caixa);
        caixa->estado = 0;

        // Realocar clientes para outros caixas abertos
        NodaFila *temp = caixa->fila->frente;
        while (temp)
        {
            Cliente *cliente = temp->cliente;
            int novo_caixa = -1;

            for (int i = 0; i < 5; i++)
            {
                if (mercado->caixas[i]->estado)
                {
                    novo_caixa = i;
                    break;
                }
            }

            if (novo_caixa != -1)
            {
                adicionar_cliente(mercado->caixas[novo_caixa]->fila, cliente);
                printf("Cliente %s realocado para o caixa %d.\n", cliente->nome, novo_caixa + 1);
            }
            else
            {
                printf("Nenhum caixa aberto disponível! Cliente %s será perdido.\n", cliente->nome);
                free(cliente);
            }

            temp = temp->proximo;
        }

        free(caixa->fila);
        caixa->fila = criar_fila();
    }
    else
    {
        printf("Abrindo caixa %d...\n", id_caixa);
        caixa->estado = 1;
    }
}

void imprimir_clientes_espera(Supermercado *mercado)
{
    printf("\n=== Clientes em Espera ===\n");
    for (int i = 0; i < 5; i++)
    {
        if (mercado->caixas[i]->estado)
        {
            printf("Caixa %d:\n", mercado->caixas[i]->id);
            imprimir_fila(mercado->caixas[i]->fila);
        }
    }
}

void imprimir_status(Supermercado *mercado)
{
    printf("\n=== Status dos Caixas ===\n");
    for (int i = 0; i < 5; i++)
    {
        int qtd_clientes = 0;
        NodaFila *temp = mercado->caixas[i]->fila->frente;
        while (temp)
        {
            qtd_clientes++;
            temp = temp->proximo;
        }

        printf("Caixa %d [%s] - Clientes na fila: %d\n",
               mercado->caixas[i]->id,
               mercado->caixas[i]->estado ? "Aberto" : "Fechado",
               qtd_clientes);
    }
}

void destruir_supermercado(Supermercado *mercado)
{
    for (int i = 0; i < 5; i++)
    {
        free(mercado->caixas[i]);
    }
    free(mercado);
}