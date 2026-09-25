#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funções_PilhasFilhas.h"



int main(){
  int opcao, Vu1, Vu2;
  int qtd;
  int valorRemovido;
  Pilha p1;
  PilhaEncadeada p2;


  incializarPilha(&p1);
  inicializarPilhaEnc(&p2);

  do{
  limparTela();



   printf("**==============**\n");
   printf("|------ MENU ----|\n");
   printf("**==============**\n");

   imprimirPilha(&p1);

   imprimirPilhaEnc(&p2);


   printf("1) Insira um valor na pilha(sequencial)\n");
   printf("2) Insira um valor na pilha(cadeada)\n");
   printf("3) Exluir um valor na pilha(senquencial)\n");
   printf("4) Exluir um valor na pilha(cadeada)\n");

   printf("digite a opcao que voce quer realizar: \n");
    scanf("%d", &opcao);


  switch(opcao){


 case 1:
     printf("digite o valor a ser inserido: \n");
     scanf("%d", &Vu1);
     push(&p1, Vu1);

     finalizar();
     break;

 case 2:
    printf("digite o valor a ser inserido: \n");
    scanf("%d", &Vu2);
    pushEnc(&p2, Vu2);

    finalizar();
    break;

 case 3:
     printf("\nDigite quantos numeros voce quer remover da pilha sequencial: ");
       scanf("%d", &qtd);

        for (int i = 0; i < qtd; i++) {
            if (pop(&p1, &valorRemovido)) {
                printf("Elemento %d removido com sucesso!\n", valorRemovido);
        } else {
            break;
    }
 }
        finalizar();
          break;

 case 4:
    printf("\nDigite quantos numeros voce quer remover da pilha sequencial: ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
            if (popEnc(&p2, &valorRemovido)) {
                printf("Elemento %d removido com sucesso!\n", valorRemovido);
        } else {
            break;
    }
 }
        finalizar();
          break;

  }
}while(opcao != 0);




  return 0;
}
