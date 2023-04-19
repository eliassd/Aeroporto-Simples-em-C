#include <stdio.h>
#include <stdlib.h>


void EstornarVoo(){
  char voo[11],passagem[11],preco[11];
  int Estorno,Ipassagem;
  float Fpreco;

  FILE *arq;

  printf("Digite o voo que deseja Estornar: ");
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

  printf("Digite a quantidade de passagens que deseja estornar: ");
  scanf("%d",&Estorno);

  Ipassagem += Estorno;

  arq = fopen(voo,"w+");
  fprintf(arq,"%d\n",Ipassagem);
  fprintf(arq,"%s",preco);

  fclose(arq);
}