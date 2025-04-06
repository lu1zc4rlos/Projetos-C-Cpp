#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void limpar_tela()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

string palavra_aleatoria()
{
    string palavras[27] = {"dexter", "debra", "angel", "cody", "joey", "harry", "rita", "laguerta", "arthur", "vince", "astor", "rita",
                           "harry", "harryson", "trinity", "dokes", "brayan", "hanna", "style", "louis", "liam", "niall", "zayn", "peralta", "santiago", "mike"};
    int valor = rand() % 27;
    return palavras[valor];
}

string palavra_mascara(int tamanho_palavra)
{
    return string(tamanho_palavra, '_');
}

void status(int tamanho_palavra, string &mensagem, string &palavra_com_mascara,
            int &tentativas, string &letras_arriscadas)
{
    cout << mensagem << "\n";
    cout << "Palavra: " << palavra_com_mascara << " (Tamanho: " << tamanho_palavra << ")\n";
    cout << "Tentativas restantes: " << tentativas << "\n";

    cout << "Letras arriscadas: ";
    for (int cont = 0; cont < letras_arriscadas.size(); cont++)
    {
        cout << letras_arriscadas[cont] << ",";
    }
    cout << "\n";
}

void jogar(int *jogador)
{
    bool jogar_novamente = true;

    while (jogar_novamente)
    {
        jogar_novamente = false;
        limpar_tela();
        string palavra;
        if (*jogador == 1)
            palavra = palavra_aleatoria();
        else
        {
            cout << "Digite uma palavra a ser adivinhada: ";
            cin >> palavra;
            limpar_tela();
        }
        int tamanho_palavra = palavra.size();
        string palavra_com_mascara = palavra_mascara(tamanho_palavra);

        int tentativas = 10;
        char letra;
        string chute_palavra;
        string letras_arriscadas;
        bool voce_acertou = false, ja_digitou = false;
        string mensagem = "Bem vindo ao jogo";
        int cont = 0;

        while (palavra != palavra_com_mascara && tentativas > 0)
        {
            status(tamanho_palavra, mensagem, palavra_com_mascara, tentativas, letras_arriscadas);

            cout << "\nDigite uma letra (Ou digite 1 para arriscar uma palavra): ";
            cin >> letra;

            if (letra == '1')
            {
                limpar_tela();
                cout << "Digite a palavra chute: ";
                cin >> chute_palavra;
                if (chute_palavra == palavra)
                {
                    limpar_tela();
                    cout << "Parabens, voce venceu!\n\n";
                    cout << "Tecle ENTER para voltar...";
                    _getch();
                    limpar_tela();
                    return;
                }
                else
                {
                    limpar_tela();
                    cout << "Nao foi dessa vez!\n";
                    cout << "Palavra certa: " << palavra << "\n\n";
                    cout << "Tecle ENTER para voltar...";
                    _getch();
                    limpar_tela();
                    return;
                }
            }
            for (cont = 0; cont < letras_arriscadas.size(); cont++)
            {
                if (letra == letras_arriscadas[cont])
                {
                    mensagem = "Essa letra ja foi digitada";
                    ja_digitou = true;
                }
            }
            if (ja_digitou == false)
            {
                letras_arriscadas.push_back(letra);

                for (cont = 0; cont < tamanho_palavra; cont++)
                {
                    if (palavra[cont] == letra)
                    {
                        palavra_com_mascara[cont] = palavra[cont];
                        mensagem = "Voce acertou uma letra";
                        voce_acertou = true;
                    }
                }
            }
            if (voce_acertou == false && ja_digitou == false)
            {
                mensagem = "Voce errou uma letra";
                tentativas--;
            }
            voce_acertou = false;
            ja_digitou = false;

            limpar_tela();
        }
        int opcao;
        if (palavra_com_mascara == palavra)
        {
            cout << "Parabens, voce venceu!\n\n";
            cout << "Quer jogar novamente?\n";
            cout << "1. Sim\n";
            cout << "2. Nao\n";
            cout << "Digite aqui: ";
            cin >> opcao;
            limpar_tela();
            if (opcao == 1)
            {
                jogar_novamente = true;
                cout << "1. Sozinho\n";
                cout << "2. Em dupla\n";
                cout << "Opecao: ";
                cin >> *jogador;
            }
            else
            {
                return;
            }
        }
        else
        {
            cout << "Nao foi dessa vez!\n";
            cout << "Palavra certa: " << palavra << "\n\n";
            cout << "Quer jogar novamente?\n";
            cout << "1. Sim\n";
            cout << "2. Nao\n";
            cout << "Digite aqui: ";
            cin >> opcao;
            limpar_tela();

            if (opcao == 1)
            {
                jogar_novamente = true;
                cout << "1. Sozinho\n";
                cout << "2. Em dupla\n";
                cout << "Opecao: ";
                cin >> *jogador;
            }
            else
            {
                return;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int opcao = 0;
    int jogador = 0;
    while (1)
    {
        cout << "Bem vindo ao Jogo\n";
        cout << "1 - Jogar sozinho\n";
        cout << "2 - Jogar em Dupla\n";
        cout << "3 - Sobre\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opcao e tecla ENTER: ";
        cin >> opcao;
        limpar_tela();

        switch (opcao)
        {
        case 1:
            jogador = 1;
            jogar(&jogador);
            break;
        case 2:
            jogador = 2;
            jogar(&jogador);
            break;
        case 3:
            cout << "Jogo desenvolvido por Luiz Carlos para fins de estudo\n";
            cout << "LinkedIn: www.linkedin.com/in/luiz-carlos-b335142b6\n";
            cout << "Um dia voce vai olhar para tras e vai perceber que todo o esforco valeu a pena.\n\n";
            cout << "Tecle ENTER para voltar...";
            _getch();
            limpar_tela();
            break;
        case 4:
            limpar_tela();
            return 0;
        default:
            cout << "Opcao escolhida nao existe!\n\n";
            cout << "Tecle ENTER para voltar...";
            _getch();
            limpar_tela();
            break;
        }
    }

    return 0;
}