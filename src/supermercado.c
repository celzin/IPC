#include "includes/supermercado.h"

Supermercado *criar_supermercado()
{
    Supermercado *mercado = (Supermercado *)malloc(sizeof(Supermercado));
    if (mercado)
    {
        for (int i = 0; i < MAX_CAIXAS; i++)
        {
            mercado->caixas[i] = criar_caixa(i + 1);
        }
    }
    return mercado;
}

void cadastrar_cliente(Supermercado *mercado)
{
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    int prioridade, itens, id_caixa;

    // Validação de Nome
    do
    {
        printf("Nome: ");
        getchar();
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = 0;

        if (!validar_nome(nome))
        {
            printf("Nome inválido! Digite apenas letras e espaços.\n");
        }
    } while (!validar_nome(nome));

    // Validação de CPF
    do
    {
        printf("CPF (11 dígitos): ");
        scanf("%s", cpf);
        if (!validar_cpf(cpf))
        {
            printf("CPF inválido! Digite um CPF válido de 11 dígitos.\n");
        }
    } while (!validar_cpf(cpf));

    // Validação de Prioridade
    do
    {
        printf("Prioridade (1-Alta, 2-Média, 3-Baixa): ");
        if (scanf("%d", &prioridade) != 1)
        {
            while (getchar() != '\n')
                ;
            prioridade = 0;
        }
        if (prioridade < 1 || prioridade > 3)
        {
            printf("Prioridade inválida! Escolha 1, 2 ou 3.\n");
        }
    } while (prioridade < 1 || prioridade > 3);

    // Validação de Itens
    do
    {
        printf("Itens no carrinho: ");
        if (scanf("%d", &itens) != 1 || itens < 1)
        {
            printf("Entrada inválida! Digite um número de itens válido (maior que 0).\n");
            while (getchar() != '\n')
                ;
            itens = 0;
        }
    } while (itens < 1);

    // Validação de Caixa
    do
    {
        printf("Escolha o caixa (1-%d): ", MAX_CAIXAS);
        if (scanf("%d", &id_caixa) != 1)
        {
            while (getchar() != '\n')
                ;
            id_caixa = 0;
        }
        if (id_caixa < 1 || id_caixa > MAX_CAIXAS)
        {
            printf("Número de caixa inválido! Escolha entre 1 e %d.\n", MAX_CAIXAS);
        }
        else if (!mercado->caixas[id_caixa - 1]->estado)
        {
            printf("Caixa %d está fechado! Escolha outro caixa.\n", id_caixa);
        }
    } while (id_caixa < 1 || id_caixa > MAX_CAIXAS || !mercado->caixas[id_caixa - 1]->estado);

    Cliente *novo_cliente = criar_cliente(nome, cpf, prioridade, itens);
    adicionar_cliente(mercado->caixas[id_caixa - 1]->fila, novo_cliente);
}

void atender_cliente_supermercado(Supermercado *mercado)
{
    int id_caixa;
    printf("Escolha o caixa (1-%d): ", MAX_CAIXAS);
    scanf("%d", &id_caixa);

    if (id_caixa < 1 || id_caixa > MAX_CAIXAS)
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
    int caixas_abertos = 0;

    // Conta quantos caixas estão abertos
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        if (mercado->caixas[i]->estado)
        {
            caixas_abertos++;
        }
    }

    printf("Escolha o caixa (1-%d) para abrir ou fechar: ", MAX_CAIXAS);
    scanf("%d", &id_caixa);

    if (id_caixa < 1 || id_caixa > MAX_CAIXAS)
    {
        printf("Número de caixa inválido! Escolha entre 1 e %d.\n", MAX_CAIXAS);
        return;
    }

    Caixa *caixa = mercado->caixas[id_caixa - 1];

    if (caixa->estado)
    {
        // Se for o último caixa aberto, impedir o fechamento
        if (caixas_abertos == 1)
        {
            printf("Erro! Não é possível fechar o último caixa aberto.\n");
            return;
        }

        printf("Fechando caixa %d...\n", id_caixa);
        caixa->estado = 0;

        // Realocar clientes para outros caixas abertos
        NodaFila *temp = caixa->fila->frente;
        while (temp)
        {
            Cliente *cliente = temp->cliente;
            int novo_caixa = -1;

            // Encontrar um novo caixa aberto para o cliente
            for (int i = 0; i < MAX_CAIXAS; i++)
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

        // Destruir a fila antiga e criar uma nova vazia
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
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        // if (mercado->caixas[i]->estado)
        // {
        //     printf("Caixa %d [%s]:\n", mercado->caixas[i]->id, mercado->caixas[i]->estado ? "Aberto" : "Fechado");
        //     imprimir_fila(mercado->caixas[i]->fila);
        // }
        printf("Caixa %d [%s]:\n", mercado->caixas[i]->id, mercado->caixas[i]->estado ? "Aberto" : "Fechado");
        imprimir_fila(mercado->caixas[i]->fila);
    }
}

void imprimir_status(Supermercado *mercado)
{
    printf("\n=== Status dos Caixas ===\n");
    for (int i = 0; i < MAX_CAIXAS; i++)
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
    for (int i = 0; i < MAX_CAIXAS; i++)
    {
        free(mercado->caixas[i]);
    }
    free(mercado);
}