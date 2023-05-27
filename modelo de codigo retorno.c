/*molde para programa de retorno */

main(){
    int continuar = 1;

    while (continuar !=0){
           system("cls");

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
        /* Inclusao de codigo aqui */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    char nome [80];
    float sal_bruto, sal_liquido, inss;
  
    
    printf(" Digite o nome do Funcionario:");
    scanf("%s", &nome);
    if (strlen(nome) > 80){
        printf("Nome invalido");
        return 0;
    }

    printf(" Digite o valor do Salario Bruto:");
    scanf("%f", &sal_bruto);
    
    if (sal_bruto >= 0 ){

        if (sal_bruto > 0 && sal_bruto <= 1302.00  )
        {
            inss = (7.5 * sal_bruto) / 100;
         

        }else if ( sal_bruto > 1302.00 && sal_bruto <= 2571.29 )
        { 
             inss = (9 * sal_bruto) / 100;
             

        }else if ( sal_bruto > 2571.29 && sal_bruto <= 3856.94 )
        {
            inss = (12 * sal_bruto) / 100;
         

        }else if ( sal_bruto > 3856.94 && sal_bruto <= 7507.49 )
        {
            inss = (14 * sal_bruto) / 100;
            
        }else 
            {
                printf("Valor invalido");
            }   
    }
        sal_liquido = sal_bruto - inss;
    

        printf("\n Funcionario: %s", nome);
        printf("\n Salario Bruto e de : R$ %.2f", sal_bruto);
        printf("\n inss a ser descontado e de: R$ %.2f", inss);
        printf("\n Salario Liquido e de : R$ %.2f", sal_liquido);
            
     
        
        printf("\n Deseja continuar? (1 - sim 0 - nao):");
        scanf("%i", &continuar);

    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++==
float sal_liquido(float sal_bruto){
    float inss;

 if (sal_bruto > 0 ){

        if (sal_bruto > 0 && sal_bruto <= 1302.00  )
        {
            inss = (7.5 * sal_bruto) / 100;
           

        }else if ( sal_bruto > 1302.00 && sal_bruto <= 2571.29 )
        { 
             inss = (9 * sal_bruto) / 100;
             

        }else if ( sal_bruto > 2571.29 && sal_bruto <= 3856.94 )
        {
            inss = (12 * sal_bruto) / 100;
           

        }else if ( sal_bruto > 3856.94 && sal_bruto <= 7507.49 )
        {
            inss = (14 * sal_bruto) / 100;
           
        }else 
            {
              inss = -999;
            }   
    }

    return inss;
}


main(){
    float sb = 0;
    float resultado;
    resultado = sal_liquido(sb);
    printf("O valor do inss  %.2f", resultado);
}


