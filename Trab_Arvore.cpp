#include <stdio.h>
#include <stdlib.h>

struct no_arvore
{
	no_arvore * esq;
	int info;
	no_arvore * dir;
};

typedef no_arvore ARVORE;

void Insere(ARVORE **R, int n)
{
	if (*R==NULL)
	{
 		(*R)=(ARVORE *) calloc(1,sizeof(ARVORE));
  		(*R)->info=n;
  		(*R)->esq=NULL;
  		(*R)->dir=NULL;
}
	else  if (n<(*R)->info)
		  Insere(&(*R)->esq, n);
	    else
		  Insere(&(*R)->dir,n);
}


void Pre_Order(ARVORE *R)
{
	if (R!=NULL)
	{
		printf("%d ", R->info);
		Pre_Order(R->esq);
		Pre_Order(R->dir);
	}
}

void In_Order(ARVORE *R)
{
	if (R!=NULL)
	{
		In_Order(R->esq);
		printf("%d ", R->info);
		In_Order(R->dir);
	}
}

void Pos_Order(ARVORE *R)
{
	if (R!=NULL)
	{
		Pos_Order(R->esq);
		Pos_Order(R->dir);
		printf("%d ", R->info);
	}
}

ARVORE *BuscaDoFilho (ARVORE *R, int v)
{
	if (R==NULL)
	   return NULL;
	else
	   if(R->info==v)
			return R;
	   else
	      if (R->info > v)
		 	return BuscaDoFilho (R->esq,v);
	      else
		 	return BuscaDoFilho (R->dir,v);
}


ARVORE *BuscaDoPai (ARVORE *R, ARVORE *F)
{
	if (R==NULL)
	   return NULL;
	else
		if(R->esq==F || R->dir==F)
			return R;
	   	else
	      	if (R->info > F->info)
		 		return BuscaDoPai (R->esq,F);
	     	 else
		 		return BuscaDoPai (R->dir,F);

}


void remove(ARVORE **pai, ARVORE **filho)
{

	//Primeiro caso, o alvo é uma folha
	if(((*filho)->esq==NULL) && ((*filho)->dir==NULL)){
		if((*filho)->info>(*pai)->info)
			(*pai)->dir=NULL;
		else
			(*pai)->esq=NULL;
		free(*filho);
	}
	else{
		//Segundo caso, o alvo tem uma folha
		if(((*filho)->esq==NULL) || ((*filho)->dir==NULL)){
			//O alvo esta a direita do seu pai
			if((*filho)->info>(*pai)->info){
				if((*filho)->dir==NULL){
					(*pai)->dir=(*filho)->esq;
					free(*filho);
				}
				else{
					(*pai)->dir=(*filho)->dir;
					free(*filho);
				}
			}
			else{
				// o alvo esta a esquerda do seu pai
				if((*filho)->dir==NULL){
					(*pai)->esq=(*filho)->esq;
					free(*filho);
				}
				else{
				(*pai)->esq=(*filho)->dir;
				free(*filho);
				}
			}
		}
		else{
			//o alvo tem duas folhas, e a sua folha a direita tem mais folhas a direita mds
			if((*filho)->dir->esq!=NULL){
				if((*filho)->info>(*pai)->info){
					(*pai)->dir=(*filho)->dir->esq;
					(*pai)->dir->esq=(*filho)->esq;
					(*pai)->dir->dir=(*filho)->dir;
					(*filho)->dir->esq=NULL;
					free(*filho);
				}
				else{
					(*pai)->esq=(*filho)->dir->esq;
					(*pai)->esq->esq=(*filho)->esq;
					(*pai)->esq->dir=(*filho)->dir;
					(*filho)->dir->esq=NULL;
					free(*filho);
				}

			}
			else
			//O alvo tem apenas duas folhas e mais nada ufa
				if((*filho)->info>(*pai)->info){
					(*pai)->dir=(*filho)->dir;
					(*filho)->dir->esq=(*filho)->esq;
					free(*filho);
				}
				else{
					(*pai)->esq=(*filho)->dir;
					(*filho)->dir->esq=(*filho)->esq;
					free(*filho);
				}
		}
	}
}

main()
{
	ARVORE *Raiz, *pai,*filho;
	int op, n, v;

	Raiz = NULL; // criando a arvore vazia

	do
	{
		printf("\n--------------------------------------------\n");
		puts("1. Inserir");
		puts("2. Percursos");
		puts("3. Remover");
		puts("0. Sair");
		printf("\nOpcao: ");
		scanf("%d", &op);

		switch(op)
		{
			case 1: printf("\nDigite o valor do no:");
			        scanf("%d", &n);
			       	Insere(&Raiz,n);
			        break;

			case 2: printf("\nPre_Order: ");
			        Pre_Order(Raiz);
			        printf("\nIn_Order : ");
			        In_Order(Raiz);
			        printf("\nPos_Order: ");
			        Pos_Order(Raiz);

			        break;

			case 3:	printf("Digite o valor a ser removido:");
					scanf("%d",&v);
					filho = BuscaDoFilho(Raiz,v);
					pai = BuscaDoPai(Raiz,filho);
					remove(&pai,&filho);
					printf("Valor removido");

					break;


		}
	} while (op!=0);
}






