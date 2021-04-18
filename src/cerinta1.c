#include "heap.h"

/**
 * TODO: Alocati memorie si cititi datele din fisier
 * @param  **v: vectorul cu datele citite
 * @param  dimensiune: dimensiunea vectorului
 * @param  input: fisierul de intrare
 * @retval None
 */
void readVector(int **v, int dimensiune, FILE *input)
{
    int num = 0;
    *v = (int *)malloc(sizeof(int) * dimensiune);
    for (int i = 0; i < dimensiune; i++)
    {
        fscanf(input, "%d", &num);
        (*v)[i] = num;
    }
    // for (int i = 0; i < dimensiune; i++)
    // {
    //     printf("%d ",(*v)[i]);
    // }
}

/** 
 * TODO:   Stergeti elementul de pe pozitia i din heap
 * @param  *h: heap binar 
 * @param  i: index-ul elementului ce trebuie sters din heap
 * @retval None
 */
void deleteNode(Heap *h, int i)
{
    h->vec[i] = h->vec[(h->size) - 1];
    (h->size)--;
    if (h->vec[i] < h->vec[parent(h, i)])
        while (i > 0 && h->vec[i] < h->vec[(i - 1) / 2])
        {
            h->vec[i] = h->vec[(i - 1) / 2];
            i = (i - 1) / 2;
        }
    else
        heapify(h, i);
}
/**
 * TODO: Implementati algoritmul heapsort
 * @param  *h: heap-ul binar ce contine datele vectorului sortat
 * @param  *buf: vectorul ce trebuie sortat
 * @param  dimensiune: dimensiunea vectorului ce trebuie sortat
 * @retval None
 */
void heapsort(Heap *h, int *buf, int dimensiune)
{
    if (h == NULL || buf == NULL || dimensiune == 0)
        while (dimensiune > h->capacity)
            resize(h);
    for (int i = 0; i < dimensiune; i++)
        h->vec[i] = buf[i];
    h->size = dimensiune;
    for (int i = (dimensiune - 1) / 2 - 1; i >= 0; i--)
    {
        heapify(h, i);
    }
    for (int i = dimensiune - 1; i >= 0; i--)
    {
        int aux = h->vec[0];
        h->vec[0] = h->vec[i];
        h->vec[i] = aux;
        h->size = i;
        heapify(h, 0);
    }
    h->size = dimensiune;
    // printHeap(h);
}
