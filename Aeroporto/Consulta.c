#include <stdio.h>

void ConsultarPas(){
  char voo[11],passagem[11],preco[11];

  FILE *arq;

  printf("Digite o voo que deseja consultar: ");
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

  fclose(arq);

}