#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <pthread.h>

using namespace std;

#define SIZE 10

double time1, timedif;// variáveis para o contador
int v[SIZE]; 

// declarando as matrizes utilizadas
int mat_a[3][3] = {{1,3,2},{4,1,2},{9,2,3}};
int mat_b[3][3] = {{7,2,1},{8,9,1},{8,4,3}};
int mat_c[3][3] = {0,0,0,0,0,0,0,0,0};

int i; //linhas de A
int j; //colunas de B
int k; //para  cada linha em A, percorer as células


void *print_mat_a(void * arg){
    cout << "Executando thread 1... \n";
    cout << "Imprimindo a Matriz A: \n";
    for (int i = 0; i < 3; i++){
        cout << "|";
            for (int j = 0; j < 3; j++){
                cout << mat_a[i][j] << "|";
            }
        cout << "\n";
    }
    pthread_exit(NULL);
    return NULL;
}
void * print_mat_b(void *arg){
    cout << "Executando thread 2... \n";
    cout << "Imprimindo a Matriz B: \n";
    for (int i = 0; i < 3; i++){
        cout << "|";
            for (int j = 0; j < 3; j++){
                cout << mat_b[i][j] << "|";
            }
        cout << "\n";
    }
    pthread_exit(NULL);
    return NULL;
}
void print_mat_c(){
    cout << "O resultado da multiplicação de A x B foi: \n";
    for (int i = 0; i < 3; i++){
        cout << "|";
            for (int j = 0; j < 3; j++){
                cout << mat_c[i][j] << "|";
            }
        cout << "\n";
    }
}

void * multiplica_matriz(void *arg){
    cout << "Executando thread 3... \n";
    for(i = 0; i < 3; i ++){
        for(j = 0; j < 3; j ++){
            for(k = 0; k < 3; k++){
                mat_c[i][j] = mat_c[i][j] + mat_a[i][k] * mat_b [k][j];
            }
        }
    }
    cout << "Thread 3 concluida, matrizes multiplicadas... \n";
    pthread_exit(NULL);
    return NULL;
}
int main(){
time1 = (double) clock();
time1 = time1 / CLOCKS_PER_SEC;

pthread_t t1, t2, t3;
int a1 = 1, a2 = 2, a3 = 3;


pthread_create(&t1, NULL, print_mat_a, (void *)(&a1));; //cria thread 1
pthread_create(&t2, NULL, print_mat_b, (void *)(&a2)); //cria thread 2
pthread_create(&t3, NULL, multiplica_matriz, (void *)(&a3)); //cria thread 3



setlocale(LC_ALL, "Portuguese");

pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);


print_mat_c();




timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("Tempo executado: %f segundos\n", timedif);

    pthread_exit(NULL);
exit (0);
}