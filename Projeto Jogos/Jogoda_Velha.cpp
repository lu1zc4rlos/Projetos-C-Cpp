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

void inicia_tabuleiro(char tabuleiro[3][3])
{
    int linha, coluna;
    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            tabuleiro[linha][coluna] = '-';
        }
    }
}

void exibe_tabuleiro(char tabuleiro[3][3])
{
    int linha, coluna;
    cout << "\n";
    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            cout << tabuleiro[linha][coluna] << " ";
        }
        cout << "\n";
    }
}

int confere_tabuleiro(char tabuleiro[3][3])
{
    int linha, coluna;
    for (linha = 0; linha < 3; linha++)
    {
        if (tabuleiro[linha][0] == 'X' && tabuleiro[linha][1] == 'X' && tabuleiro[linha][2] == 'X')
        {
            return 1;
        }
        else if (tabuleiro[linha][0] == 'O' && tabuleiro[linha][1] == 'O' && tabuleiro[linha][2] == 'O')
        {
            return 2;
        }
    }
    for (coluna = 0; coluna < 3; coluna++)
    {
        if (tabuleiro[0][coluna] == 'X' && tabuleiro[1][coluna] == 'X' && tabuleiro[2][coluna] == 'X')
        {
            return 1;
        }
        else if (tabuleiro[0][coluna] == 'O' && tabuleiro[1][coluna] == 'O' && tabuleiro[2][coluna] == 'O')
        {
            return 2;
        }
    }
    if (tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
    {
        if (tabuleiro[0][0] == 'X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    if (tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
    {
        if (tabuleiro[0][2] == 'X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    return 0;
}

void exibe_instrucoes()
{
    cout << "\nMapa de instrucoes: ";
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3\n\n";
}

void exibe_pontuacao(int pontuacao_jogador1, int pontuacao_jogador2, string nome_jogador1, string nome_jogador2)
{
    cout << "Pontuacao atual:\n";
    cout << nome_jogador1 << ": " << pontuacao_jogador1 << "\n";
    cout << nome_jogador2 << ": " << pontuacao_jogador2 << "\n\n";
}

void jogo(string nome_jogador1, string nome_jogador2, int &pontuacao_jogador1, int &pontuacao_jogador2)
{
    int linha_jogada, coluna_jogada, posicao_jogada;
    int turno_do_jogador = 1;
    int rodada = 0;
    int estado_de_jogo = 1;
    char tabuleiro[3][3];
    string jogador_atual;

    inicia_tabuleiro(tabuleiro);

    while (rodada < 9 && estado_de_jogo == 1)
    {
        cout << "Rodada: " << rodada << "\n";
        if (turno_do_jogador == 1)
        {
            jogador_atual = nome_jogador1;
        }
        else
        {
            jogador_atual = nome_jogador2;
        }
        limpar_tela();
        exibe_tabuleiro(tabuleiro);
        exibe_instrucoes();
        exibe_pontuacao(pontuacao_jogador1, pontuacao_jogador2, nome_jogador1, nome_jogador2);
        int posicoes[9][2] = {{2, 0}, {2, 1}, {2, 2}, {1, 0}, {1, 1}, {1, 2}, {0, 0}, {0, 1}, {0, 2}};

        cout << "\n" << jogador_atual << ", digite uma posicao conforme o mapa acima: ";
        cin >> posicao_jogada;

        linha_jogada = posicoes[posicao_jogada - 1][0];
        coluna_jogada = posicoes[posicao_jogada - 1][1];
        if (tabuleiro[linha_jogada][coluna_jogada] == '-')
        {
            if (turno_do_jogador == 1)
            {
                tabuleiro[linha_jogada][coluna_jogada] = 'X';
                turno_do_jogador = 2;
            }
            else
            {
                tabuleiro[linha_jogada][coluna_jogada] = 'O';
                turno_do_jogador = 1;
            }
            if (confere_tabuleiro(tabuleiro) == 1)
            {
                limpar_tela();
                exibe_tabuleiro(tabuleiro);
                cout << "Jogador " << nome_jogador1 << " venceu!\n";
                pontuacao_jogador1++;
                estado_de_jogo = 0;
            }
            else if (confere_tabuleiro(tabuleiro) == 2)
            {
                limpar_tela();
                exibe_tabuleiro(tabuleiro);
                cout << "Jogador " << nome_jogador2 << " venceu!\n";
                pontuacao_jogador2++;
                estado_de_jogo = 0;
            }
            rodada++;
        }
    }

    if (estado_de_jogo == 1)
    {
        limpar_tela();
        exibe_tabuleiro(tabuleiro);
        cout << "Empate!\n";
    }
    cout << "Tecle ENTER...";
    _getch();
    limpar_tela();
    cout << "Fim do jogo, deseja jogar novamente?\n";
    cout << "1. Continuar jogo\n";
    cout << "2. Ir para o menu\n";
    cout << "3. Sair\n";
    cout << "Opcao: ";
    int opcao;
    cin >> opcao;
    switch (opcao)
    {
    case 1:
        limpar_tela();
        jogo(nome_jogador1, nome_jogador2, pontuacao_jogador1, pontuacao_jogador2);
        break;
    case 2:
        limpar_tela();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Opcao escolhida nao existe!\n\n";
        cout << "Tecle ENTER para voltar...";
        _getch();
        limpar_tela();
        break;
    }
}

int main()
{
    int opcao = 0;
    int pontuacao_jogador1 = 0, pontuacao_jogador2 = 0;
    string nome_jogador1, nome_jogador2;

    while (1)
    {
        cout << "Bem vindo ao jogo\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao e tecla ENTER: ";
        cin >> opcao;
        limpar_tela();

        switch (opcao)
        {
        case 1:
            if (nome_jogador1.empty() && nome_jogador2.empty())
            {
                cout << "Digite o nome do jogador 1: ";
                cin >> nome_jogador1;
                cout << "Digite o nome do jogador 2: ";
                cin >> nome_jogador2;
            }
            jogo(nome_jogador1, nome_jogador2, pontuacao_jogador1, pontuacao_jogador2);
            break;
        case 2:
            cout << "Jogo desenvolvido por Luiz Carlos para fins de estudo\n";
            cout << "LinkedIn: www.linkedin.com/in/luiz-carlos-b335142b6\n";
            cout << "Um dia voce vai olhar para tras e vai perceber que todo o esforco valeu a pena.\n\n";
            cout << "Tecle ENTER para voltar...";
            _getch();
            limpar_tela();
            break;
        case 3:
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