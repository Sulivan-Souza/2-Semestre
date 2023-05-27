/*molde para programa de retorno */

main(){
    int continuar = 1;

    while (continuar !=0){
           system("cls");

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
        /* Inclusao de codigo aqui */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    char nome [80];
    float sal_bruto, sal_liquido, INSS;
    int porcentagem;
    
    printf(" Digite o nome do Funcionario:");
    scanf("%s", &nome);
    if (strlen(nome) > 80){
        printf("Nome invalido");
        return 0;
    }

    printf(" Digite o valor do Salario Bruto:");
    scanf("%f", &sal_bruto);
    
    if (sal_bruto > 0 ){

        if (sal_bruto > 0 && sal_bruto <= 1302.00  )
        {
            INSS = (7.5 * sal_bruto) / 100;
            porcentagem = 7.5;

        }else if ( sal_bruto > 1302.00 && sal_bruto <= 2571.29 )
        { 
             INSS = (9 * sal_bruto) / 100;
             porcentagem = 9;

        }else if ( sal_bruto > 2571.29 && sal_bruto <= 3856.94 )
        {
            INSS = (12 * sal_bruto) / 100;
            porcentagem = 12;

        }else if ( sal_bruto > 3856.94 && sal_bruto <= 7507.49 )
        {
            INSS = (14 * sal_bruto) / 100;
            porcentagem = 14;
        }else 
            {
                printf("Valor invalido");
            }   
    }
        sal_liquido = sal_bruto - INSS;
    

        printf("\n Funcionario: %s", nome);
        printf("\n Salario Bruto e de : R$ %.2f", sal_bruto);
        printf("\n Valor da porcentagem de desconto e: %.2d%%", porcentagem);
        printf("\n INSS a ser descontado e de: R$ %.2f", INSS);
        printf("\n Salario Liquido e de : R$ %.2f", sal_liquido);
            
     
        
        printf("\n\nDeseja continuar? (1 - sim 0 - nao):");
        scanf("%i", &continuar);

    }/* while */

}/* - MAIN - fim do programa*/