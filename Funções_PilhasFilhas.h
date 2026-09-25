#ifndef FUNçõES_PILHASFILHAS_H
#define FUNçõES_PILHASFILHAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

void limparTela(){
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
}




typedef struct{
  int itens[TAM_MAX];
  int topo;
}Pilha;



void incializarPilha(Pilha *p){
  p->topo = -1;
}

int pilhaVazia(Pilha *p){
   return p->topo == -1;
}

int pilhaCheia(Pilha *p){
   return p->topo == TAM_MAX - 1;
}

int push(Pilha *p, int valor) {
   if (pilhaCheia(p)){
    printf("Erro: pilha cheia\n");
    return 0;
   }
   p->topo++;
   p->itens[p->topo] = valor;
   return 1;
}

 int pop(Pilha *p, int *valorRemovido){
   if(pilhaVazia(p)){
    printf("Erro: pilha vazia\n");
    return 0;
   }
   *valorRemovido = p->itens[p->topo];
   p->topo--;
   return 1;
 }

 void imprimirPilha(Pilha *p){
   if(pilhaVazia(p)){
    printf("\nA está vazia.\n");
  } else {
    printf("A pilha tem elementos\n");
  }

  if(pilhaCheia(p)){
    printf("A pilha está cheia.\n");
  } else {
      printf("Ainda cabe elementos na pilha\n");
  }

  if(pilhaVazia(p)){
    printf("Pilha vazia\n");
  } else {
  printf("Pilha (topo -> base): \n");
  for(int i = p->topo; i>= 0; i--){
    printf("%d \n", p->itens[i]);
     }
    printf("\n");
   }

 }




#endif // FUNçõES_PILHASFILHAS_H
