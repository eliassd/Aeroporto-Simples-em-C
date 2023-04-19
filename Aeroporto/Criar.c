#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CriarVoo(){
  FILE * arq;
  char nomeVoo[10],passagem[11],preco[11];
  //Pega as variaveis
  printf("Digite o nome do voo: ");
  fgets(nomeVoo,10,stdin);
  
  printf("Digite a quantidade de passagens disponiveis: ");
  fgets(passagem,10,stdin);

  printf("Digite o preço das passagens: ");
  fgets(preco,10,stdin);

  //incrementa o final txt
  nomeVoo[strlen(nomeVoo)-1] = '\0';
  strcat(nomeVoo,".txt");

  strcat(passagem,preco);

  arq = fopen(nomeVoo,"w+");
  fprintf(arq,"%s",passagem);

  fclose(arq);

}
