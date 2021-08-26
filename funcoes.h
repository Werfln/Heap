#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCOES_H
#define FUNCOES_H

void insertion_sort(int *vet, int n)
{
    int i, chave;

    for(int j = 2; j <= n; j++)
    {
        chave = vet[j];
        i = j - 1;

        while(i >= 0 && vet[i] > chave)
        {
            vet[i + 1] = vet[i];
            i--;
        }

        vet[i + 1] = chave;
    }
}

void subir(int *heap, int i)
{
    int j = i/2;
    if(j >= 1)
    {
        if(heap[i] > heap[j])
        {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            subir(heap, j);
        }
    }
}

void descer(int *heap, int i, int n)
{
    int e = i*2;
    int d = (i*2) + 1;
    int maior = i;
    if(e <= n && heap[e] > heap[i])
        maior = e;

    if(d <= n && heap[d] > heap[maior])
        maior = d;

    if(maior != i)
    {
        int temp = heap[i];
        heap[i] = heap[maior];
        heap[maior] = temp;
        descer(heap, maior, n);
    }
}

int inserir(int *heap, int novo, int n)
{
    heap = (int *) realloc(heap, sizeof(int) * (n + 2));
    n = n+1;
    heap[n] = novo;
    subir(heap, n);

    return n;
}

int remover(int *heap, int n)
{
    heap[1] = heap[n];
    n = n-1;
    heap = (int *) realloc(heap, sizeof(int) * (n + 1));
    descer(heap, 1, n);

    return n;
}

void construir(int *heap, int n)
{
    int j = n/2;
    for(int i = j; i >= 1; i--)
        descer(heap, i, n);
}

void heap_sort(int *heap, int n)
{
    int j = n;
    construir(heap, n);
    for(int i = n; i > 1; i--)
    {
        int temp = heap[i];
        heap[i] = heap[1];
        heap[1] = temp;

        j--;

        descer(heap, 1, j);
    }
}

#endif // FUNCOES_H