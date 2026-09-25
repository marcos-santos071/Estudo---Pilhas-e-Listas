#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funções_PilhasFilhas.h"



int main(){
  int opcao, Vu;
  Pilha p;

  incializarPilha(&p);

  do{
  limparTela();



   printf("**==============**\n");
   printf("|------ MENU ----|\n");
   printf("**==============**\n");

   imprimirPilha(&p);

   printf("1) Insira um valor na pilha");

   printf("digite a opcao que voce quer realizar: \n");
    scanf("%d", &opcao);


  switch(opcao){



 case 1:
     printf("digite o valor a ser inserido: \n");
     scanf("%d", &Vu);
     push(&p, Vu);

     printf("\nDigite ENTER para retornar ao menu\n");
     getchar();
     getchar();


  }
}while(opcao != 0);




  return 0;
}
