#include "heap.h"

/**
 * TODO: Returnati un vector ce contine cele mai mari k elemente din vector.
 * HINT: Nu trebuie sa sortati tot vectorul, se poate utiliza un heap de
 * dimensiune mai mica. Pentru sortarea intregului vector se pot aplica penalizari
 * @param  *buffer: vectorul initial
 * @param  dimensiune: dimensiunea vectorului
 * @param  k: numarul de elemente returnate
 * @retval - vectorul cu cele mai mari k elemente din buffer
 */
int *kMaxElem(int *buffer, int dimensiune, int k)
{
    Heap *heap = create(k);
    populateHeap(heap, buffer, k);
    
    for (int i = k; i < dimensiune; i++)
    {
        if (heap->vec[0] < buffer[i])
        {
            heap->vec[0] = buffer[i];
            heapify(heap, 0);
        }
    }
    
    int *vect, i = 0;
    vect = (int *)calloc(k, sizeof(int));

    while (i < k)
    {
        vect[k - i - 1] = heap->vec[0];
        heap->size--;
        heap->vec[0] = heap->vec[heap->size];
        heapify(heap, 0);
        i++;
    }
    return vect;
}
