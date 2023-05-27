#include <stdio.h> // biblioteca de entrada e saida de dados
#include <string.h> //biblioteca manipulacao texto para usar
#include <conio.h> // biblioteca para usar o getch

struct modelo_pessoa
{
    char nome[30];
    int idade;
    float salario ;
};

struct modelo_pessoa pessoa[3];//quantidade de dados de entradas

int main()
{
  int indice =0;
  int opcao;
  int continuar = 1;
  int alterar = 0;
  int i;
    
  while(continuar != 0)
  { 
    system("cls");
    printf(" -- MENU PRINCIPAL --\n\n");
    printf("     1 - INCLUIR\n");
    printf("     2 - LISTAR\n");
    printf("     3 - ALTERAR\n");
    printf("     4 - EXCLUIR\n");
    printf("     5 - SAIR\n\n");
    printf("  ESCOLHA UMA OPCAO: ");
    scanf  ("%d", &opcao);

    /////////////////////INCLUIR////////////////////////////////
    if(opcao == 1)
    {   
      system("cls");

      printf("-- INCLUIR  PESSOAS --\n\n");
      /* PROGRAMA DA OPCAO 1 AQUI*/
      if (indice < 3)
      {
        system("cls");

        printf("PESSOA %i \n\n", (indice + 1));
        printf("Digite o nome da pessoa : ");
        scanf("%s", pessoa[indice].nome);
        printf("\nDigite a idade da pessoa : ");
        scanf("%i", &pessoa[indice].idade);
           
        printf("\nDigite o salario da pessoa: ");
        scanf("%f", &pessoa[indice].salario); 
                         
        indice++ ;
        printf("\n\nPessoa adicionado com sucesso!\n");
        printf("\n\nDigite uma tecla para continuar");
        getch();

      } else 
      {           
        printf(" Nao e possivel adicionar mais pessoas\n\n Pressione uma tecla para continuar : ");
        printf("\nDigite uma tecla para continuar\n");
        getch();
      }   
    } 
    /////////////////////////LISTAR///////////////////////////////
            
    else if(opcao == 2)
    {
      system("cls");
      printf("-- LISTAR PESSOAS --\n\n"); 
      /* PROGRAMA DA OPCAO 2 AQUI*/
      if ( indice == 0)
      {
        printf(" Nao existe registro de pessoas\n\n Pressione uma tecla para retornar : ");
        getch();
      }
      else
      {
        printf("| %-10s |%-30s | %10s | %10s |\n", "Num","Nome","Idade","Salario");
        for(i = 0;i < indice; i++)
        {
          printf("| %-10i |%-30s | %10i | %10.2f |\n", (i + 1), pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
        }
        printf("\nDigite uma tecla para continuar\n");
        getch();
      }
    }
      /////////////////////ALTERAR////////////////////////////    
    else if(opcao == 3)
    {
      system("cls");
      printf("-- ALTERAR PESSOAS--\n\n");
      /* PROGRAMA DA OPCAO 3 ALTERAR*/
      if ( indice == 0)
      {
        printf(" Nao ha registros para alteracao\n\n Pessione uma tecla para continuar:");
        getch();
      }else
      {
        printf("Qual entrada voce quer alterar : ");
        scanf("%i", &alterar );
        if ( alterar > 0 && alterar <= indice )
        {            
          alterar-- ;

          printf("|%-30s | %10i | %10.2f |\n",  pessoa[alterar].nome, pessoa[alterar].idade, pessoa[alterar].salario);
          printf("\nDigite o nome da pessoa :");
          scanf("%s", pessoa[alterar].nome);
          printf("\nDigite a idade da pessoa :");
          scanf("%i", &pessoa[alterar].idade);
          
          printf("\nDigite o salario da pessoa:");
          scanf("%f", &pessoa[alterar].salario);
           
          printf("\n\nPessoa alterada com sucesso!\n");
          printf("\n\nDigite uma tecla para continuar");
          getch();
        }
        else
        {
          printf(" Entrada nao encontrada...");
          printf(" Digite uma tecla para volta ao menu");
          getch();
        }             
      }
    }
    ///////////////////EXCLUIR/////////////////////////
    else if(opcao == 4)
    {
      system("cls");
      printf("-- EXCLUIR PESSOAS --\n\n");
      /* PROGRAMA DA OPCAO 4 AQUI*/
      if ( indice == 0)
      {
        printf(" Nao ha registros para exclusao\n\n Pessione uma tecla para continuar:");
        getch();
      }else
      {
        printf("Qual entrada voce quer excluir : ");
        scanf("%i", &alterar );
        if ( alterar > 0 && alterar <= indice )
        {             
         alterar-- ;
         printf("|%-30s | %10i | %10.2f |\n",  pessoa[alterar].nome, pessoa[alterar].idade, pessoa[alterar].salario);
         printf("\n\nDeseja excluir esta entrada? (1 - Sim / 2 - Nao): ");
         scanf("%i", &opcao);
         if(opcao == 1)
         {
          for(i = alterar; i < indice; i++)  
          {
            strcpy(pessoa[i].nome, pessoa[i + 1].nome);
            pessoa[i].idade = pessoa[i + 1].idade;
            pessoa[i].salario = pessoa[i + 1].salario;
          }
          indice--;
          printf("\n\nPessoa excluida com sucesso!\n");
          printf("\n\nDigite uma tecla para continuar");
          getch();
          }
          else
          {
            printf("\n\nPessoa nao excluida!\n");
            printf("\n\nDigite uma tecla para continuar");
            getch();
          }
        }else
        {
          printf(" Entrada nao encontrada...");
          printf(" Digite uma tecla para volta ao menu");
          getch();
        }
      }
    }
    //////////////////////////SAIR/////////////////////////////
    else if(opcao == 5)
    {
      int op;
      system("cls");
      printf("--  SAIR  --\n\n");
      /* PROGRAMA DA OPCAO 4 AQUI*/
      printf("\n\nVoce deseja sair do programa? (1 - Sim / 2 - Nao): ");            
      scanf("%i", &op);
      if(op == 2)
      {
        continuar = 1;
      }
      else
      { 
        system("cls");
        printf("Obrigado por usar o programa\n\n");
                 
        exit(0);
      }
    }         
  }
}

