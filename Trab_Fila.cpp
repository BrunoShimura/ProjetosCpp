#include <stdio.h>
#include <stdlib.h>

struct  no
{
	struct no * esq;
	int info;
	struct no * dir;
};
typedef struct no Lista;

void Cria_LDE(Lista **Inicio, Lista **Fim)
{
	*Inicio=NULL;
	*Fim=NULL;
}

void Ins_Inicio (Lista **Inicio, Lista **Fim, int v)
{
	Lista * p = (Lista *)calloc (1, sizeof(Lista)) ;
	p->info = v;
	p->esq = NULL;
	p->dir = *Inicio;
	if (*Inicio==NULL)
	   *Fim =p;
	else
	   (*Inicio)->esq=p;
	 *Inicio = p;
}

void Ins_Fim (Lista **Inicio, Lista **Fim, int v)
{
	Lista * p = (Lista *)calloc (1, sizeof(Lista)) ;
	p->info = v;
	p->esq = *Fim;
	p->dir = NULL;
	if (*Inicio==NULL)
	   *Inicio =p;
	else
	   (*Fim)->dir=p;
	 *Fim = p;
}

void Imprime (Lista *Inicio)
{
   Lista *p;
   p=Inicio;

   while (p!=NULL)
	{
		if ((p->info/1000)==1)
            printf("<-N%d", p->info);
        else
        if ((p->info/1000)==2)
            printf("<-I%d", p->info);
        else
        if ((p->info/1000)==3)
            printf("<-D%d", p->info);
        else
        if ((p->info/1000)==4)
            printf("<-G%d", p->info);
        p=p->dir;
	}
}

int Rem_Inicio (Lista **Inicio, Lista **Fim, int *v)
{
	Lista *p;
	if (*Inicio!=NULL)
	{
		p=*Inicio;
		*Inicio= p->dir;
		if (p->dir==NULL)  // só existe 1 nó na lista
		   *Fim=NULL;
		else
		   (*Inicio)->esq=NULL;
		*v=p->info;
		free(p);
		return 1;
	}
	else return 0;
}

Lista * Consulta(Lista *Inicio, int v)
{
	Lista *p = Inicio;

	while((p!=NULL)&&(p->info!=v))
	   p = p->dir;

	return p;
}

void Ins_Depois(Lista *r, int v)
{
	Lista *p = (Lista*)calloc(1,sizeof(Lista));

	p->info = v;

	p->esq = r;
	p->dir = r->dir;

	r->dir->esq = p;
	r->dir = p;

}

main()
{
    Lista *Inicio, *Fim, *r1,*r2,*r3,*r4;
    int op, val,val1=3000,val2=2000,val3=4000,val4=1000,op2;
    int uVal1,uVal2,uVal3,uVal4;


    Cria_LDE(&Inicio,&Fim); // criando lista vazia

	do
	{
        printf("\n--------------------------------------------\n");
		puts("1. Inserir Paciente");
		puts("2. Atender");
		puts("3. Imprimir");
		puts("0. Sair");

		printf("\nOpcao:");
		scanf("%d", &op);

	    switch(op)
	    {
	    	case 1: printf("\n--------------------------------------------\n");
                    puts("1. Deficiente");
                    puts("2. Idoso");
                    puts("3. Gestante");
                    puts("4. Normal");

                    printf("\nOpcao:");
                    scanf("%d", &op2);

                    switch(op2)
                    {
                        case 1:
                                r1 = Consulta(Inicio,uVal1);
                                if(r1==NULL)
                                    Ins_Inicio(&Inicio, &Fim, val1);
                                else
                                if(r1==Fim)
                                    Ins_Fim(&Inicio, &Fim, val1);
                                else
                                    Ins_Depois(r1,val1);

                                printf("\nInsercao com sucesso!%");
                                uVal1=val1;
                                val1++;
                                break;

                        case 2:
                                r1 = Consulta(Inicio,uVal1);
                                r2 = Consulta(Inicio,uVal2);
                                if((r1==NULL)&&(r2==NULL))
                                    Ins_Inicio(&Inicio, &Fim, val2);
                                else
                                if((r1==Fim)||(r2==Fim))
                                    Ins_Fim(&Inicio, &Fim, val2);
                                else
                                if (r2!=NULL)
                                    Ins_Depois(r2,val2);
                                else
                                if (r1!=NULL)
                                    Ins_Depois(r1,val2);
                                else
                                    Ins_Depois(r2,val2);
                                printf("\nInsercao com sucesso!");
                                uVal2=val2;
                                val2++;

                                break;

                        case 3:
                                r1 = Consulta(Inicio,uVal1);
                                r2 = Consulta(Inicio,uVal2);
                                r3 = Consulta(Inicio,uVal3);
                                if((r1==NULL)&&(r2==NULL)&&(r3==NULL))
                                    Ins_Inicio(&Inicio, &Fim, val3);
                                else
                                if((r1==Fim)||(r2==Fim)||(r3==Fim))
                                    Ins_Fim(&Inicio, &Fim, val3);
                                else
                                if (r3!=NULL)
                                    Ins_Depois(r3,val3);
                                else
                                if (r2!=NULL)
                                    Ins_Depois(r2,val3);
                                else
                                if (r1!=NULL)
                                    Ins_Depois(r1,val3);
                                else
                                    Ins_Depois(r3,val3);
                                printf("\nInsercao com sucesso!");
                                uVal3=val3;
                                val3++;

                                break;

                        case 4:
                                r1 = Consulta(Inicio,uVal1);
                                r2 = Consulta(Inicio,uVal2);
                                r3 = Consulta(Inicio,uVal3);
                                r4 = Consulta(Inicio,uVal4);
                                if((r1==NULL)&&(r2==NULL)&&(r3==NULL)&&(r4==NULL))
                                    Ins_Inicio(&Inicio, &Fim, val4);
                                else
                                if((r1==Fim)||(r2==Fim)||(r3==Fim)||(r4==Fim))
                                    Ins_Fim(&Inicio, &Fim, val4);
                                else
                                if (r4!=NULL)
                                    Ins_Depois(r3,val4);
                                else
                                    Ins_Depois(r4,val4);
                                printf("\nInsercao com sucesso!");
                                uVal4=val4;
                                val4++;

                                break;

                    }
                    break;

	    	case 2: printf("\n--------------------------------------------\n");
                    if (Rem_Inicio(&Inicio,&Fim,&val)){
                        if ((val/1000)==1)
                            printf("\nFoi atendido:N%d", val1);
                        else
                        if ((val/1000)==2)
                            printf("\nFoi atendido:I%d", val2);
                        else
                        if ((val/1000)==3)
                            printf("\nFoi atendido:D%d", val3);
                        else
                        if ((val/1000)==4)
                            printf("\nFoi atendido:G%d", val4);
                    }
	    	        else
	    	            printf("\nFila Vazia!");

	    	        break;

			case 3: printf("\n--------------------------------------------\n");
                    if(Inicio == NULL)
                        printf("\nLista Vazia!");
                    else
                    {
                        printf("\n\nLista:\n\n");
                        Imprime(Inicio);
                    }
					break;
		}


	} while (op!=0);

}



