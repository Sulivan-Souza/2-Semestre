// media de nota

# include<stdio.h>

main(){

float nota[10], somador = 0, media;
int i;

for(i=0; i < 10; i++){
    printf("Digite a nota %i:", (i+1));
    scanf("%f", &nota[1]);

    somador = somador + nota[1];

}

media = somador / 10;
printf("media = %.2f",media);

}
