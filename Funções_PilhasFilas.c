#include "Funções_PilhasFilas.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


/* ========================================================
   1. PILHA ESTÁTICA (ARRAY/VETOR)
   ======================================================== */

void finalizar(){
  printf("\nDigite ENTER para retornar ao menu\n");
     getchar();
     getchar();
}

void incializarPilha(Pilha *p1) {
    p1->topo = -1;
}

int pilhaVazia(Pilha *p1) {
    return p1->topo == -1;
}

int pilhaCheia(Pilha *p1) {
    return p1->topo == TAM_MAX - 1;
}

int push(Pilha *p1, int valor) {
    if (pilhaCheia(p1)) {
        printf("Erro: pilha cheia\n");
        return 0;
    }
    p1->topo++;
    p1->itens[p1->topo] = valor;
    return 1;
}

int pop(Pilha *p1, int *valorRemovido) {
    if (pilhaVazia(p1)) {
        printf("Erro: pilha vazia\n");
        return 0;
    }
    *valorRemovido = p1->itens[p1->topo];
    p1->topo--;
    return 1;
}

void imprimirPilha(Pilha *p1) {
    if (pilhaVazia(p1)) {
        printf("\nA pilha estatica esta vazia.\n");
    } else {
        printf("Pilha Estatica (topo -> base): \n");
        for (int i = p1->topo; i >= 0; i--) {
            printf("%d \n", p1->itens[i]);
        }
        printf("\n");
    }
}


/* ========================================================
   2. PILHA DINÂMICA (LISTA ENCADEADA)
   ======================================================== */


void inicializarPilhaEnc(PilhaEncadeada *p2) {
    p2->topo = NULL;
}

int pilhaEncVazia(PilhaEncadeada *p2) {
    return p2->topo == NULL;
}

int pushEnc(PilhaEncadeada *p2, int valor) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return 0;
    }

    novo->valor = valor;
    novo->abaixo = p2->topo; // O novo nó passa a apontar para o antigo topo
    p2->topo = novo;        // E se torna o novo topo
    return 1;
}

int popEnc(PilhaEncadeada *p2, int *valorRemovido) {
    if (pilhaEncVazia(p2)) {
        printf("Erro: pilha encadeada vazia!\n");
        return 0; // Fica dentro das chaves
    }

    No *removido = p2->topo;
    *valorRemovido = removido->valor;
    p2->topo = removido->abaixo; // O topo passa a ser o nó de baixo
    free(removido);             // Libera a memória do nó removido
    return 1;
}

void imprimirPilhaEnc(PilhaEncadeada *p2) {
    if (pilhaEncVazia(p2)) {
        printf("\nA pilha encadeada esta vazia.\n");
        return;
    }

    printf("Pilha Encadeada (topo -> base): \n");
    No *atual = p2->topo;
    while (atual != NULL) {
        printf("%d \n", atual->valor);
        atual = atual->abaixo;
    }
    printf("\n");
}

int parentesesBalanceados(char *expressao) {

PilhaEncadeada p2;
inicializarPilhaEnc(&p2); // Inicializa a pilha de caracteres
int valorRemovido;

for (int i = 0; expressao[i] != '\0'; i++) {
    char c = expressao[i];

    if (c == '(' || c == '[' || c == '{') {
         pushEnc(&p2, c);
    }

    else if (c == ')' || c == ']' || c == '}') {

    if (pilhaEncVazia(&p2)) {
            return 0; //
    }

    popEnc(&p2, &valorRemovido);
    char topo = (char)valorRemovido;

        if ((c == ')' && topo != '(') ||
            (c == ']' && topo != '[') ||
            (c == '}' && topo != '{')) {
      return 0;
            }
        }
    }

int estaBalanceado = pilhaEncVazia(&p2);

    while (!pilhaEncVazia(&p2)) {
        popEnc(&p2, &valorRemovido);
    }

    return estaBalanceado;
}

int avaliarPosfixa(char *expressao){
 PilhaEncadeada pilha1;           //  Usando a Pilha Encadeada
 inicializarPilhaEnc(&pilha1);

 char *token = strtok(expressao, " ");
  while(token != NULL){
    if(isdigit(token[0]) || (token[0] == '-' && strlen(token) > 1)){
        pushEnc(&pilha1, atoi(token));
    }else{
        int b, a;
        popEnc(&pilha1, &b);
        popEnc(&pilha1, &a);

        if(token[0] == '+'){pushEnc(&pilha1, a + b);}
        else if(token[0] == '-'){pushEnc(&pilha1, a - b);}
        else if(token[0] == '*'){pushEnc(&pilha1, a * b);}
        else if(token[0] == '/'){pushEnc(&pilha1, a / b);}
    }
    token = strtok(NULL, " ");
  }

  int resultado;
  popEnc(&pilha1, &resultado);
  return resultado;
}
