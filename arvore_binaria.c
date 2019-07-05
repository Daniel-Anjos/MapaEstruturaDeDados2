#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando a Struct nó (apenas remover os ponteiros)
typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;

//Definindo Constantes
#define tamanho 8
#define E 0
#define D 1
#define R -1

//Criando as Variáveis
typedef struct ARVORE{
	NO *raiz;
}ARVORE;

//Declara��o da �rvore
ARVORE a;

//Prot�tipos das fun��es
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val); //Esta função é utilizada apenas para a alocação de memória
void insereNoArvoreOrdenada(int valor); //Equivale ao arvore_insere
void emOrdem(NO* raiz);


//Fun��o que sempre deve ser chamada ao se criar uma nova �rvore
void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

//Fun��o utilizada para inicializar um novo n� na �rvore
void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}

//Regra para inserção ordenada
//Valores menores ou iguais v�o � esquerda
//Valores maiores v�o � direita
void insereNoArvoreOrdenada(int valor)
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("Inserindo no %d. \n", novoNo->dado);
	
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		printf("Este é o nó raiz. \n");
		return;
	}
	
	while(corrente){
		pai = corrente;
		if(novoNo->dado <= corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				printf("No inserido � esquerda do no %d. \n", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf("No inserido � direita do no %d. \n", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}

//Executa o caminhamento em-ordem a partir do n� indicado por "raiz"
void emOrdem(NO* raiz){
	if(raiz){
		emOrdem(raiz->esq);
		printf("%d \t", raiz->dado);
		emOrdem(raiz->dir);
	}
}



int main()
{
	inicializaArvore(a);
	
	insereNoArvoreOrdenada(1);
	insereNoArvoreOrdenada(8);
	insereNoArvoreOrdenada(0);
	insereNoArvoreOrdenada(8);
	insereNoArvoreOrdenada(8);
	insereNoArvoreOrdenada(3);
  insereNoArvoreOrdenada(8);
	insereNoArvoreOrdenada(5);
	
	printf("\nBusca em ordem: \n");
	emOrdem(a.raiz);
	
}

