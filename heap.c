#include <stdio.h>
#include <stdlib.h>
#include <funcoes.h>
#include <time.h>

int main()
{
    int n = 500000;
    int aux = 0;
    clock_t tempo_is, tempo_hs; //Variáveis para fazer a contagem do tempo de execução
    int *heap = (int *) malloc(sizeof(int) * (n + 1));
    int *vet = (int *) malloc(sizeof(int) * (n + 1));

    //Geração de números aleatórios com um vetor de tamanho n
    srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            aux = rand() % n;
            vet[i] = aux;
        }

    //Chamada, realização e contagem de tempo da ordenação do insertion sort
    tempo_is = clock(); //Tempo inicial
    insertion_sort(vet, n);
    for(int i = 0; i < n; i++)
        printf("%d ", vet[i]);

    tempo_is = clock() - tempo_is; //Subtração do tempo final com o tempo inicial
    printf("\nTempo de execucao do Insertion sort: %lf segundos\n", ((double)tempo_is)/((CLOCKS_PER_SEC))); //Conversão do tempo em número real

    //Chama realização e contagem de tempo do heap sort
    tempo_hs = clock(); //Tempo inicial
    construir(vet, n);
    heap_sort(vet, n);
    for(int i = 0; i < n; i++)
        printf("%d ", vet[i]);

    tempo_hs = clock() - tempo_hs; //Subtração do tempo final com o tempo inicial
    printf("\nTempo de execucao do Heap sort: %lf segundos\n", ((double)tempo_hs)/((CLOCKS_PER_SEC))); //Conversão do tempo em número real

    free(heap);
    free(vet);

    return 0;
}
