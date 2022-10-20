/*
1) Dada uma tabela de espalhamento (Hashing Table), resultante da inserção de
registros com as chaves A, N, L, U, C, I, R, S, T, M, E, O (com cada letra
correspondendo a sua posição no alfabeto, ex: A = 1, B = 2, C = 3, ...) nesta
ordem, numa tabela inicialmente vazia de tamanho 7 e, sabendo-se que a função

de espalhamento é h(k) = (k^2 + k –1) mod 7 (mod é o resto da divisão), para a k-
ésima letra do alfabeto e que as colisões foram tratadas com listas encadeadas,

indique quantas comparações seriam necessárias para encontrar os elementos
E, T, I e M numa busca nesta tabela. Explique como você chegou a esses
valores, mostrando a tabela construída.
*/


# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

#define tam 7

typedef struct no
{
	char letra;
	struct no *prox;
} lista;


void iniciar(lista *list[])
{
	for (int i = 0; i < tam; i++)
	{
		list[i] = NULL;
	}
}

int calcular_posicao(char letra) //pass
{
	
	int valor = 0;
	int k = letra - 64;
	//printf("k = %d\n", k);
	return (k*k + k - 1) % 7;
}

void funcao_hash(lista *list[],char letra) //aparentemente pass
{
	lista *p = NULL, *nova, *aux;
	int posicao;
	posicao = calcular_posicao(letra);


	if (list[posicao] == NULL)
	{
		nova = (lista*) malloc(sizeof (lista));
		nova->letra = letra;
		nova->prox = NULL;
		p = nova;
		list[posicao] = p;
	}
	else
	{
		p = list[posicao];
		nova = (lista*) malloc(sizeof (lista));
		nova->letra = letra;
		nova->prox = p;
		p = nova;
		list[posicao] = p;
	}

}

void print_tabela(lista *list[]) //aparentemente pass
{
	lista *aux;
	for (int i = 0; i < 7; i++)
	{
		aux = list[i];
		while(aux)
		{
			printf("%c ", aux->letra);
			aux = aux->prox;
		}
		printf("\n");
	}
}

int busca(lista *list[], char pesquisa) //pass
{
	lista *aux;
	int local, cont = 0;
	local = calcular_posicao(pesquisa);
	aux = list[local];

	while (aux)
	{
		cont++;
		if (pesquisa == aux->letra)
		{
			printf("Valor '%c' encontrado na posicao (%d, %d) \n",pesquisa, local, cont);
			printf("\nPressione Enter para continuar... \n");
		    getch();
			return 0;
		}
		else
		{
			aux = aux->prox;
		}
	}
	printf("Valor '%c' nao encontrado\n", pesquisa);
	printf("\nPressione Enter para continuar... \n");
	getch();
	

}

int main()
{
	lista *list[tam];
	int opcao;
	char letra;
	iniciar(list);

	do {
	system("cls");
    printf("\nEscolha um opcao: \n");
	printf("(1) Insere um elemento na tabela.\n");
	printf("(2) Imprime a tabela.\n");
	printf("(3) Busca um elemento.\n");
	printf("(4) Sai do programa.\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	
    
    switch(opcao){
		case 1:
			printf("Digite uma letra: ");
			scanf(" %c", &letra);
			funcao_hash(list, letra);
			break;
		case 2:
			print_tabela(list);
			printf("\nPressione Enter para continuar... \n");
		    getch();
			break;
		case 3:
			printf("Digite uma letra: ");
			scanf(" %c", &letra);
			busca(list, letra);
			break;
	}
	} while (opcao !=  4);
	 
		
  return 0;
}