#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <new>
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
  int numero_cadastro;
  string nome;
  int idade;
} pessoa;

void imprimir_cadastros(int *tamanho_vetor, pessoa **ponteiro_sequencial)
{
  if (*tamanho_vetor == 0)
  {
    cout << "Sua lista esta vazia!\n";
    cout << "Pressione qualquer tecla para sair....";
    _getch();
    return;
  }

  for (int cont = 0; cont < *tamanho_vetor; cont++)
  {
    cout << "      Posicao " << cont + 1 << "\n";
    cout << "      Nome: " << (*ponteiro_sequencial)[cont].nome << "\n";
    cout << "      Idade: " << (*ponteiro_sequencial)[cont].idade << "\n\n";
    cout << "      Cadastro " << (*ponteiro_sequencial)[cont].numero_cadastro << "\n";
    cout << "--------------------------------\n\n";
  }
  cout << "Pressione qualquer tecla para sair....";
  _getch();
  return;
}

void inserir_inicio(int *tamanho_vetor, pessoa **ponteiro_sequencial)
{

  pessoa *aux_ponteiro_sequencial;

  if (*tamanho_vetor == 0)
  {
    (*tamanho_vetor)++;
    *ponteiro_sequencial = new pessoa[*tamanho_vetor];
    (*ponteiro_sequencial)[0].numero_cadastro = 1;
    cout << "Cadastro numero " << (*ponteiro_sequencial)[0].numero_cadastro << "\n";
    cout << "Digite o nome: ";
    cin >> (*ponteiro_sequencial)[0].nome;

    cout << "Digite o idada: ";
    cin >> (*ponteiro_sequencial)[0].idade;

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
      return;
      limpar_tela();
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
  while (1)
  {
    (*tamanho_vetor)++;
    aux_ponteiro_sequencial = new pessoa[*tamanho_vetor];
    for (int cont = 1; cont < *tamanho_vetor; cont++)
    {
      aux_ponteiro_sequencial[cont] = (*ponteiro_sequencial)[cont - 1];
    }

    (aux_ponteiro_sequencial)[0].numero_cadastro = *tamanho_vetor;
    cout << "Cadastro numero " << aux_ponteiro_sequencial[0].numero_cadastro << "\n";
    cout << "Digite o nome: ";
    cin >> aux_ponteiro_sequencial[0].nome;

    cout << "Digite o idade: ";
    cin >> aux_ponteiro_sequencial[0].idade;

    delete[] *ponteiro_sequencial;
    *ponteiro_sequencial = aux_ponteiro_sequencial;

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
      return;
      limpar_tela();
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
}
void inserir_final(int *tamanho_vetor, pessoa **ponteiro_sequencial)
{
  pessoa *aux_ponteiro_sequencial;

  if (*tamanho_vetor == 0)
  {
    (*tamanho_vetor)++;
    *ponteiro_sequencial = new pessoa[*tamanho_vetor];
    (*ponteiro_sequencial)[0].numero_cadastro = 1;
    cout << "Cadastro numero " << (*ponteiro_sequencial)[0].numero_cadastro << "\n";
    cout << "Digite o nome: ";
    cin >> (*ponteiro_sequencial)[0].nome;

    cout << "Digite o idade: ";
    cin >> (*ponteiro_sequencial)[0].idade;

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
      return;
      limpar_tela();
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
  while (1)
  {
    (*tamanho_vetor)++;
    aux_ponteiro_sequencial = new pessoa[*tamanho_vetor];
    for (int cont = 0; cont < *tamanho_vetor - 1; cont++)
    {
      aux_ponteiro_sequencial[cont] = (*ponteiro_sequencial)[cont];
    }

    (aux_ponteiro_sequencial)[*tamanho_vetor - 1].numero_cadastro = *tamanho_vetor;
    cout << "Cadastro numero " << aux_ponteiro_sequencial[*tamanho_vetor - 1].numero_cadastro << "\n";
    cout << "Digite o nome: ";
    cin >> aux_ponteiro_sequencial[*tamanho_vetor - 1].nome;

    cout << "Digite o idade: ";
    cin >> aux_ponteiro_sequencial[*tamanho_vetor - 1].idade;

    delete[] *ponteiro_sequencial;
    *ponteiro_sequencial = aux_ponteiro_sequencial;
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
      return;
      limpar_tela();
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
}
void inserir_posicao_escolhida(int *tamanho_vetor, pessoa **ponteiro_sequencial)
{
  pessoa *aux_ponteiro_sequencial;
  int opcao;

  if (*tamanho_vetor == 0)
  {
    cout << "Lista vazia, seu cadastro sera feito na primeira posicao!\n";
    cout << "---------------------------------------------------------\n\n";

    (*tamanho_vetor)++;
    *ponteiro_sequencial = new pessoa[*tamanho_vetor];
    (*ponteiro_sequencial)[0].numero_cadastro = 1;
    cout << "Cadastro numero " << (*ponteiro_sequencial)[0].numero_cadastro << "\n";
    cout << "Digite o nome: ";
    cin >> (*ponteiro_sequencial)[0].nome;

    cout << "Digite o idade: ";
    cin >> (*ponteiro_sequencial)[0].idade;

    cout << "\nContinuar cadastrando\n";
    cout << "1. Sim\n";
    cout << "2. Nao\n";
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
  while (1)
  {
    cout << "OBS: Escolhendo uma posicao que ja possui um cadastro, faz com que\n";
    cout << "esse cadastro e os proximos sejam jogados uma posicao para frente!\n\n";
    for (int cont = 0; cont < *tamanho_vetor; cont++)
    {
      cout << "      Posicao " << cont + 1 << "\n";
      cout << "      Nome: " << (*ponteiro_sequencial)[cont].nome << "\n";
      cout << "      Idade: " << (*ponteiro_sequencial)[cont].idade << "\n\n";
      cout << "      Cadastro " << (*ponteiro_sequencial)[cont].numero_cadastro << "\n";
      cout << "--------------------------------\n\n";
    }
    int posicao;
    cout << "OBS: O cadastro pode ser efetuado na posicao seguinte, apartir da ultima posicao!\n";
    cout << "Digite a posicao escolhida: ";
    cin >> posicao;
    if (posicao > *tamanho_vetor || posicao < 1)
    {
      printf("Posicao invalida!\n");
      printf("Voce sera redirecionado em 5 segundos!");
      sleep(5);
      limpar_tela();
      return;
      break;
    }

    (*tamanho_vetor)++;
    aux_ponteiro_sequencial = new pessoa[*tamanho_vetor];

    for (int cont = 0; cont < *tamanho_vetor - 1; cont++)
    {

      if (cont >= posicao - 1)
      {
        aux_ponteiro_sequencial[cont + 1] = (*ponteiro_sequencial)[cont];
      }
      else
      {
        aux_ponteiro_sequencial[cont] = (*ponteiro_sequencial)[cont];
      }
    }

    (aux_ponteiro_sequencial)[posicao - 1].numero_cadastro = *tamanho_vetor;
    cout << "Cadastro numero " << aux_ponteiro_sequencial[posicao - 1].numero_cadastro << "\n\n";
    cout << "Digite o nome: ";
    cin >> aux_ponteiro_sequencial[posicao - 1].nome;

    cout << "Digite o idade: ";
    cin >> aux_ponteiro_sequencial[posicao - 1].idade;

    delete[] *ponteiro_sequencial;
    *ponteiro_sequencial = aux_ponteiro_sequencial;

    limpar_tela();
    cout << "Cadastro efetuado com sucesso!\n";
    cout << "\nContinuar cadastrando\n";
    cout << "1. Sim\n";
    cout << "2. Nao\n";
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
}
void retirar_inicio(int *tamanho_vetor, pessoa **ponteiro_sequencial)
{
  pessoa *aux_ponteiro_sequencial;

  if (*tamanho_vetor == 0)
  {
    cout << "Sua lista esta vazia!\n";
    cout << "Pressione qualquer tecla para sair....";
    _getch();
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
    (*tamanho_vetor)--;
    aux_ponteiro_sequencial = new pessoa[*tamanho_vetor];
    for (int cont = 0; cont < *tamanho_vetor; cont++)
    {
      aux_ponteiro_sequencial[cont] = (*ponteiro_sequencial)[cont + 1];
    }
    delete[] *ponteiro_sequencial;
    *ponteiro_sequencial = aux_ponteiro_sequencial;
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
void retirar_final(int *tamanho_vetor, pessoa **ponteiro_sequencial)
{
  pessoa *aux_ponteiro_sequencial;

  if (*tamanho_vetor == 0)
  {
    cout << "Sua lista esta vazia!\n";
    cout << "Pressione qualquer tecla para sair....";
    _getch();
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
    (*tamanho_vetor)--;
    aux_ponteiro_sequencial = new pessoa[*tamanho_vetor];
    for (int cont = 0; cont < *tamanho_vetor; cont++)
    {
      aux_ponteiro_sequencial[cont] = (*ponteiro_sequencial)[cont];
    }
    delete[] *ponteiro_sequencial;
    *ponteiro_sequencial = aux_ponteiro_sequencial;
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
void retirar_posicao_escolhida(int *tamanho_vetor, pessoa **ponteiro_sequencial)
{
  pessoa *aux_ponteiro_sequencial;

  if (*tamanho_vetor == 0)
  {
    cout << "Sua lista esta vazia!\n";
    cout << "Pressione qualquer tecla para sair....";
    _getch();
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
    (*tamanho_vetor)--;
    aux_ponteiro_sequencial = new pessoa[*tamanho_vetor];
    for (int cont = 0; cont < *tamanho_vetor + 1; cont++)
    {
      cout << "      Posicao " << cont + 1 << "\n";
      cout << "      Nome: " << (*ponteiro_sequencial)[cont].nome << "\n";
      cout << "      Idade: " << (*ponteiro_sequencial)[cont].idade << "\n\n";
      cout << "      Cadastro " << (*ponteiro_sequencial)[cont].numero_cadastro << "\n";
      cout << "--------------------------------\n\n";
    }
    int posicao;
    cout << "Posicao escolhida: ";
    cin >> posicao;
    limpar_tela();

    for (int cont = 0; cont < *tamanho_vetor; cont++)
    {

      if (cont >= (posicao - 1))
      {
        aux_ponteiro_sequencial[cont] = (*ponteiro_sequencial)[cont + 1];
      }
      else
      {
        aux_ponteiro_sequencial[cont] = (*ponteiro_sequencial)[cont];
      }
    }

    delete[] *ponteiro_sequencial;
    *ponteiro_sequencial = aux_ponteiro_sequencial;
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
void procurar_cadastro(int *tamanho_vetor, pessoa **ponteiro_sequencial)
{
  cout << "Numero do cadastro: ";
  int n;
  cin >> n;
  limpar_tela();

  if (n <= *tamanho_vetor || n >= 0)
  {
    cout << "Cadastro encontrado!\n\n";
    cout << "--------------------------------\n";
    cout << "      Posicao " << n << "\n";
    cout << "      Nome: " << (*ponteiro_sequencial)[n - 1].nome << "\n";
    cout << "      Idade: " << (*ponteiro_sequencial)[n - 1].idade << "\n\n";
    cout << "      Cadastro " << (*ponteiro_sequencial)[n - 1].numero_cadastro << "\n";
    cout << "--------------------------------\n\n";
    cout << "Pressione qualquer tecla para sair....";
    _getch();
    limpar_tela();
    return;
  }
  else
  {
    cout << "Cadastro invalido!\n";
    cout << "Voce sera redirecionado em 5 segundos!";
    sleep(5);
    limpar_tela();
    return;
  }
}
int main()
{
  pessoa *ponteiro_sequencial;
  int tamanho_vetor = 0;

  while (1)
  {
    int opcao;
    cout << "*********************** Menu *************************** \n";
    cout << "* 1 - Insercao de um cadastro no inicio da lista       *\n";
    cout << "* 2 - Insercao de um cadastro no fim da lista          *\n";
    cout << "* 3 - Insercao de um cadastro na posicao escolhida     *\n";
    cout << "* 4 - Retirar um cadastro do inicio da lista           *\n";
    cout << "* 5 - Retirar um cadastro no fim da lista              *\n";
    cout << "* 6 - Retirar um cadastro na posicao escolhida         *\n";
    cout << "* 7 - Procurar um node com o campo numeoro de cadastro *\n";
    cout << "* 8 - Imprimir a Lista.                                *\n";
    cout << "* 9 - Sair do sistema.                                 *\n";
    cout << "******************************************************** \n";

    cout << "\nEscolha a opcao e pressione ENTER: ";
    cin >> opcao;
    limpar_tela();

    switch (opcao)
    {
    case 1:
      inserir_inicio(&tamanho_vetor, &ponteiro_sequencial);
      limpar_tela();
      break;
    case 2:
      inserir_final(&tamanho_vetor, &ponteiro_sequencial);
      limpar_tela();
      break;
    case 3:
      inserir_posicao_escolhida(&tamanho_vetor, &ponteiro_sequencial);
      limpar_tela();
      break;
    case 4:
      retirar_inicio(&tamanho_vetor, &ponteiro_sequencial);
      limpar_tela();
      break;
    case 5:
      retirar_final(&tamanho_vetor, &ponteiro_sequencial);
      limpar_tela();
      break;
    case 6:
      retirar_posicao_escolhida(&tamanho_vetor, &ponteiro_sequencial);
      limpar_tela();
      break;
    case 7:
      procurar_cadastro(&tamanho_vetor, &ponteiro_sequencial);
      limpar_tela();
      break;
    case 8:
      imprimir_cadastros(&tamanho_vetor, &ponteiro_sequencial);
      limpar_tela();
      break;
    case 9:
      limpar_tela();
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