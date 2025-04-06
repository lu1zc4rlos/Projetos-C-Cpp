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
void inicia_tabuleiro(char tabuleiro[10][10], char mascara[10][10])
{
    int linha = 0, coluna = 0;
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}
void exibir_mapa(){
    int cont = 0;
    for(cont = 0;cont<10;cont++){
       if(cont==0){
         cout << "     ";
       }
 
     cout << cont << " ";
    }
 cout << "\n";
    for(cont = 0;cont<10;cont++){
       if(cont==0){
         cout << "     ";
       }
 
     cout << "| ";
    }
    cout << "\n";
}
void exibi_tabuleiro(char mascara[10][10],char tabuleiro[10][10],bool mostrar_tabuleiro)
{

    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
 
    
    int linha,coluna;
    for(linha = 0; linha < 10; linha++){
         cout << linha << " - ";
         for(coluna = 0; coluna < 10; coluna++){
 
            switch(mascara[linha][coluna]){
                case 'A':
                    cout << blue << " " <<mascara[linha][coluna] << normal;
                    break;
                case 'P':
                    cout << green << " " <<mascara[linha][coluna] << normal;
                    break;
                default:
                    cout << " " <<mascara[linha][coluna];
                    break;
            }
 
         }
         cout << "\n";
    }
    if(mostrar_tabuleiro==true){
        for (linha = 0; linha < 10; linha++)
        {
            
            for (coluna = 0; coluna < 10; coluna++)
            {
                cout << " " << tabuleiro[linha][coluna];
            }
            cout << "\n";
        }
    }
}
void posicionar_barcos(char tabuleiro[10][10])
{
    int quantidade = 10, quantidade_posicionada = 0;
    while (quantidade_posicionada < quantidade)
    {
        int linha_aleatoria = rand() % 10;
        int coluna_aleatoria = rand() % 10;
        if (tabuleiro[linha_aleatoria][coluna_aleatoria] == 'A')
        {
            tabuleiro[linha_aleatoria][coluna_aleatoria] = 'P';
            quantidade_posicionada++;
        }
    }
}
void verificar_tipo(char tabuleiro[10][10], int linha_jogada, int coluna_jogada, int *pontos, string *mensagem)
{
    switch (tabuleiro[linha_jogada][coluna_jogada])
    {
    case 'P':
        *mensagem = "Voce acertou um barco pequeno! (10 pts)";
        *pontos += 10;
        break;
    case 'A':
        *mensagem = "Voce acertou a agua!";
        break;
    }
}
void jogo(string nome_jogador)
{
    char tabuleiro[10][10];
    int linha_jogada, coluna_jogada;
    char mascara[10][10];
    string mensagem = "Bem vindo ao jogo!";
    int pontos = 0;
    int tentativas = 0, maximo_de_tentativas = 10;
    int opcao = 0;

    inicia_tabuleiro(tabuleiro, mascara);
    posicionar_barcos(tabuleiro);

    while (tentativas < maximo_de_tentativas)
    {
        limpar_tela();
        exibir_mapa();
        exibi_tabuleiro(mascara,tabuleiro,false);
        cout << "Pontos: " << pontos << "  Tentativas Restantes: " << maximo_de_tentativas - tentativas << "\n";
        cout << mensagem << "\n";
        linha_jogada=-1;
        coluna_jogada=-1;
        while((linha_jogada<0||coluna_jogada<0)||(linha_jogada>9||coluna_jogada>9)){
        cout << nome_jogador<<", digite a linha: ";
        cin >> linha_jogada;
        cout << nome_jogador<<", digite a coluna: ";
        cin >> coluna_jogada;
        }
        verificar_tipo(tabuleiro, linha_jogada, coluna_jogada, &pontos, &mensagem);
        mascara[linha_jogada][coluna_jogada] = tabuleiro[linha_jogada][coluna_jogada];
        tentativas++;
    }
    limpar_tela();
    cout << "Fim do jogo, deseja jogar novamente?\n";
    cout << "1. Jogar Novamente\n";
    cout << "2. Ir para o menu\n";
    cout << "3. Sair\n";
    cout << "Opcao: ";
    cin >> opcao;
    switch (opcao)
    {
    case 1:
        limpar_tela();
        jogo(nome_jogador);
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
    srand((unsigned)time(NULL));
    int opcao = 0;
    string nome_jogador;
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
            cout << "Digite o nome do jogador: ";
            cin >> nome_jogador;
            limpar_tela();
            jogo(nome_jogador);
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