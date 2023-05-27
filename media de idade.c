// crie um programa que receba a idade de 8 pessoas e ao final mostre a media de idade 
//  dessas pessoas

#include <stdio.h>

int main(){
    int idade, soma = 0;
    float media;
    int i;

    for( i = 0; i < 8; i++){
        printf("Digite a idade da pessoa %i: ", (i+1));
        scanf("%i", &idade[1]);
        soma += idade[1];
    }

    media = soma / 8.0;

    printf("A media de idade das pessoas eh: %.2f\n", media);

    return 0;
}

