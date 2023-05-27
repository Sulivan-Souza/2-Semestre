

// exemplo de função
//função que calcula a parcela e divida
float calculaParcela(float totalDivida, int qtdParcelas)
{    float resutado;
    if(qtdParcelas > 0){
        if(totalDivida > 0){
            resutado = totalDivida / qtdParcelas;
            return resutado;
        }else{
            resutado = -998;
        }
    }else{
        resutado = -999;     
    }
    return resutado;
}
// main de teste
main(){

    float Divida = 1000, resultado;// pode usar qualquer nome de variavel
    int Parcelas = 10;
    resultado = calculaParcela(Divida, Parcelas);// pode usar qualquer nome de variavel
    printf("resultado : %.2f", resultado);
}