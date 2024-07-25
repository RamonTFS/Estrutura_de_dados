#include <stdio.h>
#include <stdlib.h>

int insertionSort (int vetor[], int num){ // implementação do insertion sort
    int i, key, j;
    for (i = 1; i < num; i++) {
        key = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}

void troca(int *xp, int *yp) { // definindo uma função de troca de elemento para ajudar no selection sort
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int selectionSort (int vetor[], int num){ // implementação do selection sort
    int i, j, min_idx;
    for (i = 0; i < num-1; i++) {
        min_idx = i;
        for (j = i+1; j < num; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        troca(&vetor[min_idx], &vetor[i]);
    }
}

void printVetor(int vetor[], int num) {
    for (int i = 0; i < num; i++) {
        printf("%d\n", vetor[i]);
    }
}

#define MAX_vetor 100100

int main(){

    FILE *file; // abrindo o arquivo
    file = fopen("num.100000.3.in", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int *vetor = malloc(MAX_vetor * sizeof(int)); // Aloca memória para armazenar os números
    if (vetor == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(file);
        return 1;
    }

    int n;
    int count = 0; // número de elementos do vetor
    while (fscanf(file, "%d", &n) != EOF) {
        if (count < MAX_vetor) {
            vetor[count] = n;
            count++;
        } else {
            printf("Número máximo de inteiros excedido\n");
            break;
        }
    }
    fclose(file);

    printf("vetor original: ");
    printVetor(vetor, count);
    printf("Fim do original");
    
    
    selectionSort(vetor, count);
    //insertionSort(vetor, count);  //só comentar a linha acima para e ultilizar essa para trocar como a lista está sendo ordenada
    
    printf("vetor ordenado: ");
    printVetor(vetor, count);
    printf("fim ordenado");
    return 0;
}