#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <pthread.h>

using namespace std;

#define TAM 150000

double time1, timedif;

int array[TAM];

void * load (void * arg){
    for(int i = 0; i< TAM; i++){
        array[i] = i;
    } 

    return NULL;
}

int main(){

    time1 = (double) clock();
        time1 = time1 / CLOCKS_PER_SEC;

    pthread_t t1;
    int a1 = 1;

    pthread_create(&t1, NULL, load, (void *)(&a1)); //cria thread 1
    pthread_join(t1,NULL);
    pthread_exit(NULL);
    cout << " Vetor carregado sequencialmente";
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
            printf("\nTempo executado: %f segundos em single thread", timedif);
    return 0;
}