   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   float a, b;


   void limpar_tela()
   {
      system("CLS");
   }

   void adicao()
   {
      printf("Primeiro numero: ");
      scanf("%f", &a);
      printf("Segundo numero: ");
      scanf("%f", &b);
      printf("%.0f + %.0f = %.0f\n", a, b, a + b);
   }

   void subtracao()
   {
      printf("Primeiro numero: ");
      scanf("%f", &a);
      printf("Segundo numero: ");
      scanf("%f", &b);
      printf("%.0f - %.0f = %.0f\n", a, b, a - b);
   }

   void multiplicacao()
   {
      printf("Primeiro numero: ");
      scanf("%f", &a);
      printf("Segundo numero: ");
      scanf("%f", &b);
      printf("%.0f x %.0f = %.0f\n", a, b, a * b);
   }

   void divisao()
   {
      printf("Primeiro numero: ");
      scanf("%f", &a);
      printf("Segundo numero: ");
      scanf("%f", &b);
      if(a==0||b==0){
         printf("%.2f / %.2f = 0\n", a,b);
      }
      else{
      printf("%.2f / %.2f = %.2f\n", a, b, a / b);
      }
   }

   int main()
   {
   while(1){
      int i;
      int opcao;

      printf("********************\n");
      printf("|    Calculadora   |\n");
      printf("********************\n");
      printf("| 1. Adicao        |\n");
      printf("| 2. Subtracao     |\n");
      printf("| 3. Multiplicacao |\n");
      printf("| 4. Divisao       |\n");
      printf("| 5. Sair          |\n");
      printf("********************\n");

      printf("Escolha a operacao: ");
      scanf("%d", &opcao);
      limpar_tela();

      switch (opcao)
      {
      case 1:
         adicao();
         break;
      case 2:
         subtracao();
         break;
      case 3:
         multiplicacao();
         break;
      case 4:
         divisao();
         break;
      case 5:
         limpar_tela();
         break;
      default:
         printf("Opcao escolhida nao existe!\n");
         printf("Voce sera redirecionado em 5 segundos!");
         sleep(5);
         limpar_tela();
         break;
      }

      printf("**************************\n");
      printf("|   1. Voltar ao menu    |\n");
      printf("|   2. Sair do Programa  |\n");
      printf("**************************\n");
      printf("Opcao: ");
      scanf("%d", &i);

      if (i == 1 || i == 2)
      {
         if (i == 1)
         {
            limpar_tela();
            main();
         }
         else
         {
            limpar_tela();
            printf("Fim do programa!");
            exit(0);
         }
      }
      else
      {
         printf("Opcao invalida!\n");
         printf("Retornando ao menu em 5 segundos!");
         sleep(5);
         limpar_tela();
      }
   }


      return 0;
   }