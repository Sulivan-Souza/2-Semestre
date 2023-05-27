// desenvolver uma funcao que calcule a autonomia de um veiculo, recebendo a quantidade de combustivel e o consumo em km
// por litro verificar se ambos parametros sao maiores que zero para efetuar o calculo, se nao forem retornar:
// -999 para quando tanque menor ou igual a zero
// -998 para quando consumo for menor ou igual a zero
// a formula para calculo e a multiplicacao dos parametros

// funcao autonomia de veiculo

float cal_autonomia(float combustivel,float consumo) 
{
        float autonomia;

     if (combustivel > 0){
        if (consumo > 0) {
            autonomia = combustivel * consumo;
        }else {
        autonomia = -998;
        }
    }else {
         autonomia = -999;
        }

     return autonomia;

}



main(){
    float a = 100, b =0, c;
    c = cal_autonomia(a, b);
   
    printf("A autonomia  %f", c);

}


