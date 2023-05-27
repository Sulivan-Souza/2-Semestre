/* desenvolva um programa de conversao de graus celsius para farenheit e vice-versa. 
o programa deve receber um valor real para a media de graus celsius que deve estar entre -32 à 480. 
caso esteja nesse intervalo exibir qual seria o valor respectivo em fahrenheit.
formula de conversao:C * 9/5 + 32 = F
ao final perguntar ao usuario se deseja realizar um novo calculo.
caso a resposta seja sim, o programa deve voltar ao inicio, caso contrario, o programa deve ser encerrado.
o programa deve apresentar um menu com as opcoes de conversao e, 
apos a escolha da opcao, solicitar a temperatura a ser convertida. 
o programa deve apresentar o resultado da conversao e, apos isso, voltar ao menu de opcoes. 
o programa deve ser encerrado quando a opcao de saida for escolhida. 
o programa deve apresentar uma mensagem de erro caso a opcao escolhida seja invalida.*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//-------------------------------------Calculo fahrenheit para celsius--------------//
float calc_fahrenheit(float celsius)
{
    float fahrenheit;
    if(celsius >= -32 && celsius <= 480)
    {
        fahrenheit = (celsius * 1.8) + 32;
        return fahrenheit;
    }
    else  
    {
       fahrenheit = -998;
    }
    return fahrenheit;
}
//-------------------------------------Calculo celsius para fahrenheit---------------//
float calc_celsius(float fahrenheit)
{
    float celsius;
    if(fahrenheit >= -32 && fahrenheit <= 480)
    {
        celsius = (fahrenheit - 32) / 1.8;
        return celsius;
    }
    else
    {
        celsius = -999;
    }
    return celsius; 
}
//-------------------------------------Menu-------------------------------------//
   main(){
    int opcao = 1;//variavel do menu
    float celsius, fahrenheit;//varaivel dos dados entrada
    while(opcao != 0){
        system("cls");
       printf("  |-----------------------------------------------------------|\n");
       printf("  |                                                           |\n");
       printf("  |        #####   Conversao de Temperatura   #####           |\n");
       printf("  |                                                           |\n");
       printf("  |                 Celsius para Fahrenheit  =  Opcao  -  1   |\n");
       printf("  |                                                           |\n");
       printf("  |                 Fahrenheit para Celsius  =  Opcao  -  2   |\n");
       printf("  |                                                           |\n");
       printf("  |                 Sair                     =  Opcao   - 0   |\n");
       printf("  |                                                           |\n");
       printf("  |-----------------------------------------------------------|\n");
       printf("\n Escolha uma opcao para continuar, ou  Digite '0' para Sair: ");
       scanf("%d", &opcao);
        if(opcao == 1){
            system("cls");
            printf("Celsius para Fahrenheit\n");
//----------------------------------------------------
/*programa da opcao 1*/
            printf("\nDigite a temperatura em Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = calc_fahrenheit(celsius);
            if(fahrenheit == -998){
                printf("\nValor invalido!");
            }
            else{
                printf("\nA temperatura em Fahrenheit e: %.2f", fahrenheit);
            }
            printf("\n\nDigite uma tecla para continuar");
            getch();
        }
        else if(opcao == 2){
            system("cls");
            printf("\nFahrenheit para Celsius\n");
 /*calculo opcao 2  */ 
            printf("\nDigite a temperatura em Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = calc_celsius(fahrenheit);
            if(celsius == -999){
                printf("\nValor invalido!");
            }
            else{
                printf("\nA temperatura em Celsius e: %.2f", celsius);
            }
            printf("\n\nDigite uma tecla para continuar");
            getch();
        }
        else if(opcao == 0){
            system("cls");
            printf("\nSaindo do programa...");
            printf("\ndigite uma tecla para continuar");
            getch();
        }
        else{
            system("cls");
            printf("\nOpcao invalida!");
            printf("\ndigite uma tecla para continuar");
            getch();
        }      
    }     
}







