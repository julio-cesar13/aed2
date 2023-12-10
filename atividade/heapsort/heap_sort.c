#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n ;

double startProgram, finish, elapsed;

void heapify(int arr[],int n, int i,int *cont_comparacao, int *cont_movimentacao) {
      int temp;
      int largest = i;
      int l = 2 * i + 1;
      int r = 2 * i + 2;
      *(cont_comparacao)+=1;
      if (l < n && arr[l] > arr[largest])
         largest = l;

     *(cont_comparacao)+=1;
      if (r < n && arr[r] > arr[largest])
         largest = r;

      *(cont_comparacao)+=1;
      if (largest != i) {
         temp = arr[i];
         arr[i] = arr[largest];
         arr[largest] = temp;
         *(cont_movimentacao)+=1;
 		 
 		 
         heapify(arr, n, largest, cont_comparacao, cont_movimentacao);
      }
   }
 
void heapSort(int arr[],int n, int *cont_comparacao, int *cont_movimentacao) {
   int temp;
 
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i, cont_comparacao, cont_movimentacao);
 
   for (int i = n - 1; i >= 0; i--) {
      temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
 	  
	    
      heapify(arr, i, 0, cont_comparacao, cont_movimentacao );
   }
}

