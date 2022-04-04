#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <omp.h>

double time1, timedif;

using namespace std;

void print_mat (int mat[3][3]){
    int i;
    for (int i = 0; i < 3; i++){
        cout << "|";
            for (int j = 0; j < 3; j++){
                cout << mat[i][j] << "|";
            }
        cout << "\n";
    }
}

int main(){
    #pragma omp parallel // A partir daqui tudo que estiver dentro das chaves será deixado para o compilador escolher o que será paralelizado.
    {
        time1 = (double) clock();
        time1 = time1 / CLOCKS_PER_SEC;

        setlocale(LC_ALL, "Portuguese");

        // declarando as matrizes utilizadas
        int mat_a[3][3] = {{1,3,2},{4,1,2},{9,2,3}};
        int mat_b[3][3] = {{7,2,1},{8,9,1},{8,4,3}};
        int mat_c[3][3] = {0,0,0,0,0,0,0,0,0};

        int i; //linhas de A
        int j; //colunas de B
        int k; //para  cada linha em A, percorer as células

        cout << "Imprimindo a matriz A: \n";
        print_mat(mat_a);

        cout << "Imprimindo a matriz B: \n";
        print_mat(mat_b);

        // multiplicação de matrizes

            for(i = 0; i < 3; i ++){
                for(j = 0; j < 3; j ++){
                    for(k = 0; k < 3; k++){
                        mat_c[i][j] = mat_c[i][j] + mat_a[i][k] * mat_b [k][j];
                    }
                }
            }

        cout << "Mutiplicando as Matrizes A e B conseguimos:\n";
        print_mat(mat_c);

        cout << "matriz de cria na real... \n";


        timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
            printf("Tempo executado: %f segundos em multi thread por OpenMP\n", timedif);
        
    }
    return 0;
}