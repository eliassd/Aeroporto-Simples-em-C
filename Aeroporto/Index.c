#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Comprar.c"
#include "Consulta.c"
#include "Fechar.c"
#include "Criar.c"
#include "Estornar.c"

int menu(){
  int alt;

  printf("1 - Consultar passagem\n");
  printf("2 - Comprar Passagem\n");
  printf("3 - Criar Voo\n");
  printf("4 - Fechar Voo\n");
  printf("5 - Estornar Voo\n");
  printf("0 - Finalizar Sistema\n");

  scanf("%d%*c",&alt);
  return alt;
}

int main(){
  int alt, err = 1, cont = 0, acesso = -1,aux;
  char senha[7],consulta[7];
  FILE *arq;

  arq = fopen("senha.txt","r");

  fgets(consulta,7,arq);

  fclose(arq);

  do{
    printf("Digite a senha para o acesso!\n");
    fgets(senha,7,stdin);
    acesso = strcmp(consulta,senha);
    if(acesso != 0){
      printf("Senha incorreta, digite novamente.\n\n");
    }
  }while(acesso != 0);
  
  
  while(err != 0){
    alt = menu();
    switch(alt){
      case 1:
        err = 1;
        ConsultarPas();
        break;
      case 2:
        err = 1;
        ComprarPas();
        break;
      case 3:
        err = 1;
        CriarVoo();
        break;
      case 4:
        err = 1;
        FecharVoo();
        break;
      case 5:
        err = 1;
        EstornarVoo();
        break;
      case 0:
        err = 0;
        break;
      default:
        printf("Opção invalida");
    }
  }
  return 0;
}