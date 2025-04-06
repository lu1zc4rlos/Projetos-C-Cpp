#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

void limpar_tela()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");

#endif
}
typedef struct pessoa
{
    string nome;
    int idade;
    int numero_cadastro;
    pessoa *proximo;
} pessoa;

void inserir_inicio(int *aux_numero_cadastro, pessoa **lista, int *tamanho_lista)
{
    while (1)
    {

        pessoa *aux, *novo = new pessoa;

        if (novo)
        {
            (*aux_numero_cadastro)++;
            (*tamanho_lista)++;
            novo->numero_cadastro = *aux_numero_cadastro;
            cout << "Cadastro numero " << *aux_numero_cadastro << "\n";
            cout << "Nome: ";
            cin >> novo->nome;
            cout << "Idade: ";
            cin >> novo->idade;

            novo->proximo = *lista;
            *lista = novo;
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
                aux->proximo = NULL;
            }

            cout << "\nContinuar cadastrando\n";
            cout << "1. Sim\n";
            cout << "2. Nao\n";
            int opcao;
            cout << "Opcao: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                limpar_tela();
                break;
            case 2:
                limpar_tela();
                return;
                break;
            default:
                printf("Opcao escolhida nao existe!\n");
                printf("Voce sera redirecionado em 5 segundos!");
                sleep(5);
                limpar_tela();
                return;
                break;
            }
        }

        else
        {
            cout << "Erro ao alocar memoria!";
            cout << "Precione tecla enter para continuar...";
            getchar();
            limpar_tela();
            return;
        }
    }
}
void inserir_final(int *aux_numero_cadastro, pessoa **lista, int *tamanho_lista)
{
    while (1)
    {

        pessoa *novo = new pessoa;

        if (novo)
        {
            (*aux_numero_cadastro)++;
            (*tamanho_lista)++;
            novo->numero_cadastro = *aux_numero_cadastro;
            cout << "Cadastro numero " << *aux_numero_cadastro << "\n";
            cout << "Nome: ";
            cin >> novo->nome;
            cout << "Idade: ";
            cin >> novo->idade;

            novo->proximo = NULL;
            if (*lista == NULL)
            {
                *lista = novo;
            }
            else
            {
                pessoa *aux = *lista;
                while (aux->proximo)
                {
                    aux = aux->proximo;
                }
                aux->proximo = novo;
            }

            cout << "\nContinuar cadastrando\n";
            cout << "1. Sim\n";
            cout << "2. Nao\n";
            int opcao;
            cout << "Opcao: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                limpar_tela();
                break;
            case 2:
                limpar_tela();
                return;
                break;
            default:
                printf("Opcao escolhida nao existe!\n");
                printf("Voce sera redirecionado em 5 segundos!");
                sleep(5);
                limpar_tela();
                return;
                break;
            }
        }

        else
        {
            cout << "Erro ao alocar memoria!";
            cout << "Precione tecla enter para continuar...";
            getchar();
            limpar_tela();
            return;
        }
    }
}
void inserir_posicao_escolhida(int *aux_numero_cadastro, pessoa **lista, int *tamanho_lista)
{
    int posicao;
    int cont1 = 1;
    pessoa *aux = *lista;
    cout << "OBS: Escolhendo uma posicao que ja possui um cadastro, faz com que\n";
    cout << "esse cadastro e os proximos sejam jogados uma posicao para frente!\n\n";
    cout << "OBS: O cadastro pode ser efetuado na posicao seguinte, apartir da ultima posicao!\n\n";
    while (aux)
    {
        cout << "      Posicao " << cont1 << "\n";
        cout << "      Nome: " << aux->nome << "\n";
        cout << "      Idade: " << aux->idade << "\n\n";
        cout << "      Cadastro " << aux->numero_cadastro << "\n";
        cout << "--------------------------------\n\n";
        cont1++;
        aux = aux->proximo;
    }

    while (1)
    {

        pessoa *novo = new pessoa;

        if (novo)
        {
            cout << "Digite a posicao escolhida: ";
            cin >> posicao;
            limpar_tela();

            (*aux_numero_cadastro)++;
            (*tamanho_lista)++;

            if (posicao < 1 || posicao > *aux_numero_cadastro)
            {
                (*aux_numero_cadastro)--;
                (*tamanho_lista)--;
                cout << "Posicao invalida!\n";
                cout << "Voce sera redirecionado em 5 segundos!";
                sleep(5);
                limpar_tela();
                return;
            }

            novo->numero_cadastro = *aux_numero_cadastro;
            cout << "Cadastro numero " << *aux_numero_cadastro << "\n";
            cout << "Nome: ";
            cin >> novo->nome;
            cout << "Idade: ";
            cin >> novo->idade;

            if (posicao == 1)
            {
                novo->proximo = *lista;
                *lista = novo;
            }
            else
            {
                aux = *lista;
                for (int cont = 1; cont < posicao - 1; cont++)
                {
                    aux = aux->proximo;
                }
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
        }
        else
        {
            cout << "Erro ao alocar memoria!";
            cout << "Precione tecla enter para continuar...";
            getchar();
            limpar_tela();
            return;
        }

        cout << "\nContinuar cadastrando\n";
        cout << "1. Sim\n";
        cout << "2. Nao\n";
        int opcao;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            limpar_tela();
            break;
        case 2:
            limpar_tela();
            return;
            break;
        default:
            cout << "Opcao escolhida nao existe!\n";
            cout << "Voce sera redirecionado em 5 segundos!";
            sleep(5);
            limpar_tela();
            return;
            break;
        }
    }
}

void retirar_inicio(pessoa **lista, int *tamanho_lista)
{
    pessoa *aux;
    aux = *lista;
    if (!aux)
    {
        cout << "Sua lista esta vazia!\n";
        cout << "Pressione qualquer tecla para sair....";
        getch();
        limpar_tela();
        return;
    }
    cout << "Confirmar acao.\n";
    cout << "1. Sim\n";
    cout << "2. Nao\n";
    int opcao;
    cout << "Opcao: ";
    cin >> opcao;
    if (opcao == 1)
    {
        *lista = aux->proximo;
        delete aux;
        limpar_tela();
        (*tamanho_lista)--;
        cout << "Cadastro removido!\n";
        cout << "Pressione qualquer tecla para sair....";
        _getch();
        limpar_tela();
        return;
    }
    else
    {
        cout << "Pressione qualquer tecla para sair....";
        _getch();
        limpar_tela();
        return;
    }
}
void retirar_final(pessoa **lista, int *tamanho_lista)
{
    pessoa *aux;
    aux = *lista;
    if (!aux)
    {
        cout << "Sua lista esta vazia!\n";
        cout << "Pressione qualquer tecla para sair....";
        getch();
        limpar_tela();
        return;
    }
    cout << "Confirmar acao.\n";
    cout << "1. Sim\n";
    cout << "2. Nao\n";
    int opcao;
    cout << "Opcao: ";
    cin >> opcao;
    if (opcao == 1)
    {
        if (*tamanho_lista == 1)
        {
            *lista = aux->proximo;
            delete aux;
            limpar_tela();
            (*tamanho_lista)--;
            cout << "Cadastro removido!\n";
            cout << "Pressione qualquer tecla para sair....";
            _getch();
            limpar_tela();
            return;
        }
        for (int cont = 1; cont < *tamanho_lista - 1; cont++)
        {
            aux = aux->proximo;
        }
        aux->proximo = NULL;
        delete aux;
        limpar_tela();
        (*tamanho_lista)--;
        cout << "Cadastro removido!\n";
        cout << "Pressione qualquer tecla para sair....";
        _getch();
        limpar_tela();
        return;
    }
    else
    {
        cout << "Pressione qualquer tecla para sair....";
        _getch();
        limpar_tela();
        return;
    }
}
void retirar_posicao_escolhida(pessoa **lista, int *tamanho_lista)
{
    pessoa *aux = *lista;
    int cont1 = 1;

    if (*tamanho_lista == 0)
    {
        cout << "Sua lista esta vazia!\n";
        cout << "Pressione qualquer tecla para sair....";
        _getch();
        limpar_tela();
        return;
    }
    cout << "Confirmar acao.\n";
    cout << "1. Sim\n";
    cout << "2. Nao\n";
    int opcao;
    cout << "Opcao: ";
    cin >> opcao;
    limpar_tela();
    if (opcao == 1)
    {
        while (aux)
        {
            cout << "      Posicao " << cont1 << "\n";
            cout << "      Nome: " << aux->nome << "\n";
            cout << "      Idade: " << aux->idade << "\n\n";
            cout << "      Cadastro " << aux->numero_cadastro << "\n";
            cout << "--------------------------------\n\n";
            cont1++;
            aux = aux->proximo;
        }
        int posicao;
        cout << "Posicao escolhida: ";
        cin >> posicao;
        limpar_tela();

        if (posicao < 1 || posicao > *tamanho_lista)
        {
            cout << "Posicao invalida!\n";
            cout << "Voce sera redirecionado em 5 segundos!";
            sleep(5);
            limpar_tela();
            return;
        }
        pessoa *remover;
        if (posicao == 1)
        {
            remover = *lista;
            *lista = remover->proximo;
            delete remover;
            limpar_tela();
            (*tamanho_lista)--;
            cout << "Cadastro removido!\n";
            cout << "Pressione qualquer tecla para sair....";
            _getch();
            limpar_tela();
            return;
        }
        else
        {
            aux = *lista;
            for (int cont = 1; cont < posicao - 1; cont++)
            {
                if (aux == nullptr || aux->proximo == nullptr)
                {
                    cout << "Erro: Posição inválida!\n";
                    return;
                }
                aux = aux->proximo;
            }
            remover = aux->proximo;
            if (remover == nullptr)
            {
                cout << "Erro: Posição inválida!\n";
                return;
            }

            aux->proximo = remover->proximo;
            delete remover;
            (*tamanho_lista)--;
            limpar_tela();
            cout << "Cadastro removido!\n";
            cout << "Pressione qualquer tecla para sair....";
            _getch();
            limpar_tela();
            return;
        }
    }
    else
    {
        cout << "Pressione qualquer tecla para sair....";
        _getch();
        limpar_tela();
        return;
    }
}
void procurar_cadastro(pessoa **lista)
{
    pessoa *aux = *lista;
    int cadastro = 0;
    int cont = 1;
    if (!aux)
    {
        cout << "Sua lista esta vazia!\n";
        cout << "Pressione qualquer tecla para sair....";
        _getch();
        limpar_tela();
        return;
    }

    cout << "Digite o numero do cadastro: ";
    cin >> cadastro;

    while (aux && (aux->numero_cadastro) != cadastro)
    {
        aux = aux->proximo;
        cont += 1;
    }
    if (aux)
    {
        limpar_tela();
        cout << "Cadastro numero " << aux->numero_cadastro << " encontrado\n";
        cout << "---------------------\n";
        cout << "Nome: " << aux->nome << "\n";
        cout << "Idade: " << aux->idade << "\n";
        cout << "Posicao: " << cont << "\n";
        cout << "---------------------\n";
    }
    else
    {
        cout << "Nenhum cadastro encontrado!";
    }

    cout << "\n\n";
    cout << "Precione tecla enter para continuar...";
    _getch();
    limpar_tela();
    return;
}
void imprimir_cadastros(pessoa **lista)
{
    pessoa *aux;
    aux = *lista;
    int cont = 1;
    if (!aux)
    {
        cout << "Sua lista esta vazia!\n";
        cout << "Pressione qualquer tecla para sair....";
        getch();
        limpar_tela();
        return;
    }
    else
    {
        while (aux)
        {
            cout << "      Posicao " << cont << "\n";
            cout << "      Nome: " << aux->nome << "\n";
            cout << "      Idade: " << aux->idade << "\n\n";
            cout << "      Cadastro " << aux->numero_cadastro << "\n";
            cout << "--------------------------------\n\n";
            cont++;
            aux = aux->proximo;
        }
    }

    cout << "Pressione qualquer tecla para sair....";
    getch();
    limpar_tela();
    return;
}
int main()
{
    pessoa *lista = NULL;
    int aux_numero_cadastro = 0;
    int tamanho_lista = 0;

    while (1)
    {
        int opcao;
        cout << "********************** Menu *************************** \n";
        cout << "* 1 - Insercao de um cadastro no inicio da lista      *\n";
        cout << "* 2 - Insercao de um cadastro no fim da lista         *\n";
        cout << "* 3 - Insercao de um cadastro na posicao escolhida    *\n";
        cout << "* 4 - Retirar um cadastro do inicio da lista          *\n";
        cout << "* 5 - Retirar um cadastro no fim da lista             *\n";
        cout << "* 6 - Retirar um cadastro na posicao escolhida        *\n";
        cout << "* 7 - Procurar um node com o campo numero do cadastro *\n";
        cout << "* 8 - Imprimir a Lista.                               *\n";
        cout << "* 9 - Sair do sistema.                                *\n";
        cout << "******************************************************* \n";

        cout << "\nEscolha a opcao e pressione ENTER: ";
        cin >> opcao;
        limpar_tela();

        switch (opcao)
        {
        case 1:
            inserir_inicio(&aux_numero_cadastro, &lista, &tamanho_lista);
            break;
        case 2:
            inserir_final(&aux_numero_cadastro, &lista, &tamanho_lista);
            break;
        case 3:
            inserir_posicao_escolhida(&aux_numero_cadastro, &lista, &tamanho_lista);
            break;
        case 4:
            retirar_inicio(&lista, &tamanho_lista);
            break;
        case 5:
            retirar_final(&lista, &tamanho_lista);
            break;
        case 6:
            retirar_posicao_escolhida(&lista, &tamanho_lista);
            break;
        case 7:
            procurar_cadastro(&lista);
            break;
        case 8:
            imprimir_cadastros(&lista);
            break;
        case 9:
            limpar_tela();
            exit(0);
            break;
        default:
            cout << "Opcao escolhida nao existe!\n";
            cout << "Voce sera redirecionado em 5 segundos!";
            sleep(5);
            limpar_tela();
            break;
        }
    }

    return 0;
}