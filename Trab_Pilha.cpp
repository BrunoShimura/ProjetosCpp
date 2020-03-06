#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 10

typedef struct
{
	int topo;
	int el[tam];
}Pilha;


void Cria_Pilha(Pilha *p)
{
	p->topo = -1;
}

int Cheia(Pilha *p)
{
	return p->topo == tam-1;
}

int Vazia(Pilha *p)
{
	return p->topo == -1;
}

int Push(Pilha *p, int val)
{
	if (Cheia(p))
	    return 0;  // pilha está cheia

	p->el[++p->topo] = val;
	return 1;
}


int Pop(Pilha *p, int *val)
{
	if (Vazia(p))
	   return 0; // pilha vazia

	*val = p->el[p->topo--];
	return 1;
}

void Imprime(Pilha p)
{
	int i;

	for (i=p.topo; i>=0; i--)
	     printf("[ %d ]\n",p.el[i]);
}

int Dec_Bin(Pilha *p, int v)
{
	int b = 0, x;

	while (v>0)
	{
		Push(p,v%2);
		v /=2;
	}
	while (!Vazia(p))
	{
		Pop(p,&x);

		b = b*10 + x;
	}

	return b;
}



main()
{
	Pilha s, aux;
	int op, val, bin,cont=0, x, erro=0;



	Cria_Pilha(&aux); //criando pilha vazia Auxiliar
	Cria_Pilha(&s); // criando pilha vazia

	do {
		printf("\n--------------------------------------------\n");
		puts("1. Inserir na Pilha");
		puts("2. Remover da Pilha");
		puts("3. Imprimir a Pilha");
		puts("4. Converter Decimal para Binario");
		puts("5. Digite uma Sequencia");
		puts("0. Sair do Programa");
		printf("\nOpcao:");
		scanf("%d", &op);

		switch(op)
		{
			case 1: printf("\nDigite o valor:");
			        scanf("%d", &val);
			        if (Push(&s,val))
			           printf("\nInsercao com sucesso!");
			        else
			           printf("\nPilha Cheia!");

			        break;

			case 2: if (Pop(&s,&val))
			           printf("\nFoi removido: %d", val);
			        else
			           printf("\nPilha Vazia!");

			        break;

			case 3: if (Vazia(&s))
			           printf("\nPilha Vazia!");
			        else
			        {
			        	printf("\nPilha:\n\n");
			        	Imprime(s);
					}

					break;

			case 4: printf("\nDigite um numero: ");
			        scanf("%d",&val);
			        bin = Dec_Bin(&s,val);
			        printf("\nValor em binario = %d", bin);

			        break;

			case 5 : char str[20]="";
			         int cont = 1;
			         erro=0;
			     	Cria_Pilha(&aux); //criando pilha vazia Auxiliar
	                Cria_Pilha(&s); // criando pilha vazia
			        printf("Digite um Numero:");
			         scanf("%d",&val);
					 while(val >0 )
					 {
					 	Push(&aux,val%10);
					 	val/=10;
					 }

				     do
				     {
				     	if (Vazia(&s))
				     	{
						    Push(&s,cont);
						    cont++;
						     strcat(str,"I");
						 }
						else
						  	if(s.el[s.topo]<(aux.el[aux.topo]))
                           {
						     Push(&s,cont);
							 cont++;
						     strcat(str,"I");
					   	   }
						   else
						   if (s.el[s.topo]==(aux.el[aux.topo]))
						   {
							Pop(&s, &x);
							Pop(&aux, &x) ;
							strcat(str,"R");
						    }
						    else
						    {
						     erro = 1;
							 break;

						    }
					 } while (!Vazia(&s) || (!Vazia(&aux)));

					if(erro)
					    printf("\nSequencia Invalida!");
					else
					   printf("\nSequencia Valida! %s", str);


			        break;

		}

	} while (op!=0);
}




















