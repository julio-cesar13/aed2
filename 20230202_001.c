#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char equipes[20][80];
    char nome[80];
    char sobrenome[80];
    int num_equipe = 1;
    char n;
    int i,j, tam;  
    for(i = 0;i < 20; i++){
        printf("digite o nome e sobrenome do %d mebro da equipe %d:", i, num_equipe);
        scanf("%s %s", &nome, &sobrenome);
        strcat(nome, sobrenome);
        tam = strlen(nome);
        for(j = 0; j < tam; j++){
            equipes[i][j] = nome[j];
        }
        printf("Deseja colocar o proximo integrante(s/n):");
        scanf("%c",&n);
        if( n == 'n')
           break;
        if((i + 1)% 4 == 0)
           num_equipe += 1;
    }
    

}