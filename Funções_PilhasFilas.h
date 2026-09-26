#ifndef FUNCOES_PILHASFILHAS_H
#define FUNCOES_PILHASFILHAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

// Limpeza de Tela
void limparTela();

// 1. Estrutura da Pilha Estática
typedef struct {
    int itens[TAM_MAX];
    int topo;
} Pilha;

// 2. Estrutura da Pilha Dinâmica
typedef struct No {
    int valor;
    struct No *abaixo;
} No;

typedef struct {
    No *topo;
} PilhaEncadeada;


// Função Utilitária
void finalizar();

// Funções da Pilha Estática
void incializarPilha(Pilha *p1);
int pilhaVazia(Pilha *p1);
int pilhaCheia(Pilha *p1);
int push(Pilha *p1, int valor);
int pop(Pilha *p1, int *valorRemovido);
void imprimirPilha(Pilha *p1);

// Funções da Pilha Dinâmica
void inicializarPilhaEnc(PilhaEncadeada *p2);
int pilhaEncVazia(PilhaEncadeada *p2);
int pushEnc(PilhaEncadeada *p2, int valor);
int popEnc(PilhaEncadeada *p2, int *valorRemovido);
void imprimirPilhaEnc(PilhaEncadeada *p2);
int parentesesBalanceados(char *expressao);

#endif // FUNCOES_PILHASFILHAS_H
