#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define TAM 200
int opcao;

void limpar_tela()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");

#endif
}

typedef struct Pessoa
{
    char nome[100];
    int idade;
    char idade_char[10];
    int numero_cadastro;
    char numero_cadastro_char[3];
    struct Pessoa *proximo;
} Pessoa;

void carregar_cadastro(Pessoa **lista, int *numero, FILE **filee)
{
    *filee = fopen("cadastro.txt", "r");
    if (*filee == NULL)
    {
        printf("Erro ao abrir arquivo!");
        return;
    }

    fseek(*filee, 0, SEEK_END);
    long tamanho = ftell(*filee);
    if (tamanho == 0)
    {
        return;
    }

    rewind(*filee);

    while (1)
    {
        Pessoa *aux, *novo = (Pessoa *)malloc(sizeof(Pessoa));

        if (novo == NULL)
        {
            printf("Erro ao alocar memoria!\n");
            return;
        }

        if (fgets(novo->numero_cadastro_char, sizeof(novo->numero_cadastro_char), *filee) != NULL)
        {
            novo->numero_cadastro_char[strcspn(novo->numero_cadastro_char, "\n")] = '\0';
            novo->numero_cadastro = atoi(novo->numero_cadastro_char);
        }
        else
        {
            free(novo);
            break;
            return;
        }

        if (fgets(novo->nome, sizeof(novo->nome), *filee) != NULL)
        {
            novo->nome[strcspn(novo->nome, "\n")] = '\0';
        }
        else
        {
            printf("Erro ao ler nome!\n");
            free(novo);
            return;
        }

        if (fgets(novo->idade_char, sizeof(novo->idade_char), *filee) != NULL)
        {
            novo->idade_char[strcspn(novo->idade_char, "\n")] = '\0';
            novo->idade = atoi(novo->idade_char);
        }
        else
        {
            printf("Erro ao ler idade!\n");
            free(novo);
            return;
        }

        (*numero)++;

        novo->proximo = NULL;
        if (*lista == NULL)
        {
            *lista = novo;
        }

        else
        {
            aux = *lista;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    fclose(*filee);
}

void cadastrar(Pessoa **lista, int *numero, FILE **filee)
{

    for (int cont = 0; cont < TAM; cont++)
    {
        Pessoa *aux, *novo = (Pessoa *)malloc(sizeof(Pessoa));

        if (novo)
        {
            *filee = fopen("cadastro.txt", "a");

            novo->numero_cadastro = (*numero)++;
            fprintf(*filee, "%d\n", novo->numero_cadastro);
            printf("Cadastro pessoa %d\n", novo->numero_cadastro);

            printf("Nome: ");
            fgets(novo->nome, sizeof(novo->nome), stdin);
            novo->nome[strcspn(novo->nome, "\n")] = '\0';
            fputs(novo->nome, *filee);

            printf("Idade: ");
            scanf("%d", &novo->idade);
            while (getchar() != '\n')
                ;
            fprintf(*filee, "\n%d\n", novo->idade);

            fclose(*filee);

            novo->proximo = NULL;
            if (*lista == NULL)
            {
                *lista = novo;
            }

            else
            {
                aux = *lista;
                while (aux->proximo)
                {
                    aux = aux->proximo;
                }
                aux->proximo = novo;
            }

            printf("\n*******************************\n");
            printf("| 1. Cadastrar proxima pessoa |\n");
            printf("| 2. Voltar ao menu           |\n");
            printf("*******************************\n");
            printf("opcao: ");
            scanf("%d", &opcao);
            while (getchar() != '\n')
                ;

            switch (opcao)
            {
            case 1:
                limpar_tela();
                continue;
                break;
            case 2:
                limpar_tela();
                return;
                break;

            default:
                limpar_tela();
                printf("opcao invalida!\n");
                printf("redirecionando para tela principal...");
                sleep(5);
                limpar_tela();
                return;
                break;
            }
        }
        else
        {
            printf("Erro ao alocar memoria!");
            printf("Precione tecla enter para continuar...");
            getchar();
            limpar_tela();
        }
    }
}
void listar_cadastros(Pessoa *lista)
{

    Pessoa *temp = lista;
    if (!temp)
    {
        printf("Sua lista esta vazia...");
    }
    while (temp)
    {
        printf("Cadastro numero %d\n", temp->numero_cadastro);
        printf("Nome: %s\n", temp->nome);
        printf("Idade: %d\n", temp->idade);
        printf("---------------------\n");
        temp = temp->proximo;
    }

    printf("\n\n");
    printf("Precione tecla enter para continuar...");
    getchar();
    limpar_tela();
    return;
}
void buscar_cadastro(Pessoa **lista)
{
    int buscar = 1;
    Pessoa *aux = *lista;

    if (!aux)
    {
        printf("Sua lista esta vazia...\n");
        printf("\n\nPrecione tecla enter para cadastrar...");
        getchar();
        limpar_tela();
        return;
    }

    printf("Numero do cadastro: ");
    scanf("%d", &buscar);
    while (getchar() != '\n');

    while (aux && (aux->numero_cadastro) != buscar)
    {
        aux = aux->proximo;
    }
    if (aux)
    {
        limpar_tela();
        printf("Cadastro numero %d encontrado\n", aux->numero_cadastro);
        printf("---------------------\n");
        printf("Nome: %s\n", aux->nome);
        printf("Idade: %d\n", aux->idade);
        printf("---------------------\n");
    }
    else
    {
        printf("Nenhum cadastro encontrado!");
    }

    printf("\n\n");
    printf("Precione tecla enter para continuar...");
    getchar();
    limpar_tela();
}
void alterar_cadastro(Pessoa **lista, FILE **filee)
{
    int buscar = 1;
    Pessoa *aux = *lista;
    Pessoa *temp = *lista;

    if (!aux)
    {
        printf("Sua lista esta vazia...\n");
        printf("\n\nPrecione tecla enter para cadastrar...");
        getchar();
        limpar_tela();
    }
    if (!aux)
        return;

    printf("Numero do cadastro: ");
    scanf("%d", &buscar);
    while (getchar() != '\n')
        ;

    while (aux && (aux->numero_cadastro) != buscar)
    {
        aux = aux->proximo;
    }
    if (aux)
    {
        limpar_tela();
        printf("Cadastro numero %d encontrado\n", aux->numero_cadastro);
        printf("---------------------\n");
        printf("Nome: %s\n", aux->nome);
        printf("Idade: %d\n", aux->idade);
        printf("---------------------\n\n");

        printf("************\n");
        printf("|  Alterar |\n");
        printf("************\n");
        printf("| 1. Nome  |\n");
        printf("| 2. Idade |\n");
        printf("************\n");
        int opcao;
        printf("Opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n')
            ;

        switch (opcao)
        {
        case 1:
            printf("Digite novo nome: ");
            fgets(aux->nome, sizeof(aux->nome), stdin);
            aux->nome[strcspn(aux->nome, "\n")] = '\0';
            limpar_tela();
            printf("Nome alterado com sucesso!\n");
            printf("\n\nPrecione tecla enter para voltar ao menu...");
            getchar();
            limpar_tela();

            *filee = fopen("cadastro.txt", "w");

            while (temp)
            {
                fprintf(*filee, "%d\n", temp->numero_cadastro);
                fputs(temp->nome, *filee);
                fprintf(*filee, "\n%d\n", temp->idade);
                temp = temp->proximo;
            }
            fclose(*filee);

            return;
            break;
        case 2:
            printf("Digite nova idade: ");
            scanf("%d", &aux->idade);
            while (getchar() != '\n')
                ;
            limpar_tela();
            printf("Idade alterado com sucesso!\n");
            printf("\n\nPrecione tecla enter para voltar ao menu...");
            getchar();
            limpar_tela();

            *filee = fopen("cadastro.txt", "w");

            while (temp)
            {
                fprintf(*filee, "%d\n", temp->numero_cadastro);
                fputs(temp->nome, *filee);
                fprintf(*filee, "\n%d\n", temp->idade);
                temp = temp->proximo;
            }
            fclose(*filee);

            return;
            break;
        default:
            limpar_tela();
            printf("opcao invalida!\n");
            printf("redirecionando para tela principal...");
            sleep(5);
            limpar_tela();
            return;
            break;
        }
    }
    else
    {
        printf("Nenhum cadastro encontrado!");
    }
}

int main()
{
    FILE *filee;
    filee = fopen("cadastro.txt", "a");

    Pessoa *lista = NULL;
    int numero = 1;

    fclose(filee);

    carregar_cadastro(&lista, &numero, &filee);

    while (1)
    {
        printf("***********************\n");
        printf("| Cadastro de Pessoas |\n");
        printf("***********************\n");
        printf("| 1. Cadastrar        |\n");
        printf("| 2. Listar Cadatros  |\n");
        printf("| 3. Buscar Cadastro  |\n");
        printf("| 4. Alterar Cadastro |\n");
        printf("| 5. Sair             |\n");
        printf("***********************\n");

        printf("Escolha a opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n')
            ;
        limpar_tela();

        switch (opcao)
        {
        case 1:
            cadastrar(&lista, &numero, &filee);
            break;
        case 2:
            listar_cadastros(lista);
            break;
        case 3:
            buscar_cadastro(&lista);
            break;
        case 4:
            alterar_cadastro(&lista, &filee);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Opcao escolhida nao existe!\n");
            printf("Voce sera redirecionado em 5 segundos!");
            sleep(5);
            limpar_tela();
            break;
        }
    }
    return 0;
}