#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <omp.h>
using namespace std;

#define TAM 150000

double time1, timedif;

int array[TAM];

void load (){
    for(int i = 0; i< TAM; i++){
        array[i] = i;
    }  
}

int main(){

    time1 = (double) clock();
        time1 = time1 / CLOCKS_PER_SEC;
#pragma omp parallel
{
    load();
}
    cout << " Vetor carregado sequencialmente";
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
            printf("\nTempo executado: %f segundos em single thread", timedif);
    return 0;
}