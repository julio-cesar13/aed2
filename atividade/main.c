// Driver code

// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./mergesort/merge_sort.c"
#include "./heapsort/heap_sort.c"


int cont_comparacao = 0;
int cont_movimentacao = 0;

int N;
int *arr;
char tipo[20];

void tamanho_do_vetor(char caminho[]);
void menu_algoritmo();
void impressao();
void ler_arquivo(int N, char tipo[] );
void informações(char metodo[],double elapsed, int cont_comparacao, int cont_movimentacao);
void escolher_tipo();


int main()
{
    escolher_tipo();
   
	return 0;
}



//Imprimi o vetor
void impressao()
{
	for(int i=0; i<N; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

//Abri o arquivo txt com os valores e aloca para o vetor 
void ler_arquivo(int N, char tipo[] ){
    arr = (int *) malloc (N*(sizeof(int)));
	char caminho_arquivo[35] ;
	sprintf(caminho_arquivo, "./dados/%s%d.txt", tipo,N);
	FILE *arquivo = fopen(caminho_arquivo, "r");

	if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s\n", caminho_arquivo);
        return ; // Código de erro
    }
	
	for(int i=0; i < N;i++)
		fscanf(arquivo, "%d", (arr+i));
    
	fclose(arquivo);
}

//Imprimi as informações sobre o vetor após passar pela ordenação
void informações(char metodo[],double elapsed, int cont_comparacao, int cont_movimentacao){
	printf("Tipo do Vetor: %s\n", tipo);
	printf("Tamanho do Vetor: %d\n", N);
	printf("Metodo de Ordenação: %s\n", metodo);
	printf("Tempo de Processamento:  %lf\n", elapsed);
	printf("Numero de Comparações: %d\n",cont_comparacao);
	printf("Quantidade de movimento dos registros: %d\n",cont_movimentacao);
}

//Escolhe o tipo do vetor(aleatório ou ordenado)
void escolher_tipo()
{
	int menu;
	char caminho_vetor_ordenado[] = "crescente";
	char caminho_vetor_aleatorio[] = "nova";

	printf("Escolha o tipo de vetor(aleatorio ou ordenado):\n");
	printf("\n");
	printf("************************************************** \n");
	printf("1) Aleatorio\n");
	printf("2) Ordenado\n");
	printf("3) Sair\n");
	scanf("%d", &menu);
	getchar();
	if(menu == 1){
		tamanho_do_vetor(caminho_vetor_aleatorio);
		strcpy(tipo,"aleatorio");
	}
	else if(menu == 2){
		tamanho_do_vetor(caminho_vetor_ordenado);
		strcpy(tipo,"ordenado");
	}
		
	else if(menu == 3)
		return;

}

//Escolhe o tamanho do vetor
void tamanho_do_vetor(char caminho[]){
	int menu;
	printf("\nEscolha o Tamanho do Vetor:\n");
	printf("\n");
	printf("************************************************** \n");
	printf("1 - 100 \n");
	printf("2 - 1.000 \n");
	printf("3 - 10.000 \n");
	printf("4 - 100.000 \n");
	printf("5 - Voltar\n");
	printf("6 - Sair\n");
	printf("************************************************** \n \n");
	scanf("%d", &menu);
	getchar();
    
	switch (menu)
	{
	
	case 1:
			{
				N = 100;
				ler_arquivo(N,caminho);
				menu_algoritmo();
			}
			break;
			
		case 2:
			{
			  N = 1000;
			  ler_arquivo(N, caminho);
			  menu_algoritmo();
			}
			break;
		
		case 3:
			{
			  N = 10000;
			  ler_arquivo(N, caminho);
			  menu_algoritmo();
			}
			break;
		case 4:
			{
				N = 100000;
				ler_arquivo(N, caminho);
			    menu_algoritmo();
				break;
			}
			
		case 5:
			{
               escolher_tipo();
			}
			break;
		case 6:
			{
			   free(arr);
               return;
			}
			break;
		default:
		{
			printf("Digito invalido\n");
			tamanho_do_vetor(caminho);
		}
		break;
	}
}

//Abri o menu com os algoritmos para ser feita a ordenação
void menu_algoritmo()
{
	double startProgram, finish, elapsed;
	int menu;
	int imprimir;
	int continuar;
	printf("\nEscolha o Algoritmo de Ordenação:\n");
	printf("\n");
	printf("************************************************** \n");
	printf("1 - Buble Sort \n");
	printf("2 - Insertion Sort \n");
	printf("3 - Selection Sort \n");
	printf("4 - Quick Sort \n");
	printf("5 - Shell Sort \n");
	printf("6 - Heap Sort \n");
	printf("7 - Merge Sort \n");
	printf("8 - Voltar\n");
	printf("9 - Sair\n");
	printf("************************************************** \n \n");
	scanf("%d", &menu);
    
	switch (menu)
	{
	
		case 1:
			{
				
    			
			}
			break;
			
		case 2:
			{
			  
			}
			break;
		
		case 3:
			{
			  
			}
			break;

		case 4:
			{
				
			}
			break;

		case 5:
			{

			}
			break;

		case 7:
			{
				printf("Deseja imprimir os valores do vetor?\n");
				printf("1) sim\n");
				printf("Outro numero) não\n");
				scanf("%d",&imprimir);
                if(imprimir == 1)
				{
					printf("------------------------------Vetor Inicial---------------------------------------\n");
					impressao();
                    startProgram= (double) clock() / CLOCKS_PER_SEC;
					mergeSort(arr, 0, N - 1,&cont_comparacao, &cont_movimentacao);
    				finish = (double) clock() / CLOCKS_PER_SEC;
                	elapsed= (double) finish - startProgram;
					printf("\n\n--------------------------------Vetor Final----------------------------------------\n\n");
					impressao();
					printf("--------------------------------Informações ----------------------------------------\n");
					informações("Merge Sort", elapsed, cont_comparacao, cont_movimentacao);
				}
				else
				{	
					startProgram= (double) clock() / CLOCKS_PER_SEC;
					mergeSort(arr, 0, N - 1,&cont_comparacao, &cont_movimentacao);
    				finish = (double) clock() / CLOCKS_PER_SEC;
                	elapsed= (double) finish - startProgram;
					printf("--------------------------------Informações ----------------------------------------\n");
					informações("Merge Sort", elapsed, cont_comparacao, cont_movimentacao);
				}
				cont_comparacao = 0;
				cont_movimentacao = 0;

				printf("\n\nDeseja continuar\n1)Sim\n Outro numero)Não\n ");
				scanf("%d",&continuar);
				if(continuar == 1)
					menu_algoritmo();
				else
					return;

			}
			break;

		case 6:
			{
				printf("Deseja imprimir os valores do vetor?\n");
				printf("1) sim\n");
				printf("Outro numero) não\n");
				scanf("%d",&imprimir);
                if(imprimir == 1)
				{
					printf("------------------------------Vetor Inicial---------------------------------------\n");
					impressao();
					startProgram= (double) clock() / CLOCKS_PER_SEC;
					heapSort(arr, N,&cont_comparacao, &cont_movimentacao);
    				finish = (double) clock() / CLOCKS_PER_SEC;
                	elapsed= (double) finish - startProgram;
					printf("\n\n--------------------------------Vetor Final----------------------------------------\n\n");
					impressao();
					printf("--------------------------------Informações ----------------------------------------\n");
					informações("Heap Sort",elapsed, cont_comparacao, cont_movimentacao);
				}
			    else
				{
					startProgram= (double) clock() / CLOCKS_PER_SEC;
					heapSort(arr, N,&cont_comparacao, &cont_movimentacao);
    				finish = (double) clock() / CLOCKS_PER_SEC;
                	elapsed= (double) finish - startProgram;
					printf("--------------------------------Informações ----------------------------------------\n");
					informações("Heap Sort", elapsed, cont_comparacao, cont_movimentacao);
				}
				cont_comparacao = 0;
				cont_movimentacao = 0;

				printf("\n\nDeseja continuar\n1)Sim\nOutro numero)Não\n ");
				scanf("%d",&continuar);
				if(continuar == 1)
					menu_algoritmo();
				else
					return;
			
			}
			break;
		case 8:
		{
			
			
		}
		case 9:
		{
			free(arr);
            cont_comparacao = 0;
			cont_movimentacao = 0;
			escolher_tipo();
		}
		break;
		case 10:
		{
			free(arr);
			return;
		}
		break;
		default:
		{
			printf("Digito invalido\n");
		}
		break;
	}
}
