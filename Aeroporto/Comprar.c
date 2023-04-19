#include <stdio.h>
#include <stdlib.h>


void ComprarPas(){
  char voo[11],passagem[11],preco[11];
  int Compra,Ipassagem,Plano,aux = 0;
  float Fpreco,Troco,ValorTotal;

  FILE *arq;

  printf("Digite o voo que deseja comprar: ");
  fgets(voo,11,stdin);

  voo[strlen(voo)-1] = '\0';
  strcat(voo,".txt");

  if(!(arq = fopen(voo,"r"))){
    printf("Voo não encontrado\n");
    exit(1);
  }

  fgets(passagem,11,arq);
  fgets(preco,11,arq);

  printf("\nPassagens Disponiveis: %s \n",passagem);
  printf("Preço da passagem: R$%s \n",preco);

  Ipassagem = atoi(passagem);
  Fpreco = atof(preco);

  fclose(arq);

  if(Ipassagem <=0){
    printf("\nPassagens esgotadas\n\n");
    return;
  }

  printf("Digite a quantidade de passagens que deseja comprar: ");
  scanf("%d",&Compra);

  if(Ipassagem - Compra < 0){
    printf("\nQuantidade de passagens insuficiente\n\n");
    return;
  }

  do{
  printf("\nEscolha o plano do usuário\n");

  printf("1 - Sem plano\n");
  printf("2 - Plano Básico - 10%%\n");
  printf("3 - Plano Premium - 25%%\n");

  scanf("%d",&Plano);

    switch(Plano){
      case 1:
        ValorTotal = Fpreco*Compra;
        printf("\nTotal a pagar: R$%.2f\n\n",ValorTotal);
        aux = 1;
        break;

      case 2:
        ValorTotal = (Fpreco*Compra)*0.9;
        printf("\nTotal a pagar: R$%.2f\n\n",ValorTotal);
        aux = 1;
        break;

      case 3:
        ValorTotal = (Fpreco*Compra)*0.75;
        printf("\nTotal a pagar: R$%.2f\n\n",ValorTotal);
        aux = 1;
        break;

      default:
        printf("\nOpção invalida\n\n");
        break;
    }
  }while(aux != 1);

  printf("Digite o Valor pago:R$");
  scanf("%f",&Troco);
  printf("\nValor de troco:R$%.2f\n\n",Troco-ValorTotal);

  Ipassagem -= Compra;

  arq = fopen(voo,"w+");
  fprintf(arq,"%d\n",Ipassagem);
  fprintf(arq,"%s",preco);

  fclose(arq);
}