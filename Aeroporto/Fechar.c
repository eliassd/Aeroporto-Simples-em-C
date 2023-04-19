#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FecharVoo(){
  char nome[10];
  char commando[20] = "unlink ";
  int sucesso;

  printf("Digite o nome do voo que deseja fechar\n");
  fgets(nome,10,stdin);

  nome[strlen(nome)-1] = '\0';
  strcat(nome,".txt");

  strcat(commando,nome);

  sucesso=system(commando);

  system("clear");
  if(sucesso == 0){
    printf("Voo Finalizado com sucesso\n\n");
  }else{
    printf("Voo não encontrado\n\n");
  }



}