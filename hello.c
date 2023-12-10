#include <stdio.h>
#include <math.h>

int scanIntIntervalo(){
    int num;
    printf("digite o numero:");
    scanf("%d",&num);
    while(num <= 0 || num >= 1000){
        printf("digite o numero:");
        scanf("%d",&num);
    }
    return num;
    }

float percentual(float num1, float num2){
    float maior,menor;
    float percentual;
    maior = num1;
    if (num2 > maior){
       maior = num2;
       menor = num1;
    }else
        menor = num2;

    percentual = (maior/menor)*100;
    return percentual;
    }
int absdif(int num1, int num2){
    return fabs(num2 - num1);
}
int main() 
{
    int num1,num2,mod;
    float perc;
    num1 = scanIntIntervalo();
    num2 = scanIntIntervalo();
    perc = percentual(num1,num2);     
    printf("O percentual do menor em relacao ao maior :%.2f\n",perc);
    mod = absdif(num1,num2);
    printf("E o modulo da diferenca entre os numeros:%d\n",mod);

}
