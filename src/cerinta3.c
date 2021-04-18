#include "heap.h"

/**
 * TODO: Sortati eficient un vector k-sortat folosind un heap.
 * HINT: Se poate utiliza un heap de dimensiune mai mica decat
 * numarul de elemente din buffer
 * @param  *buffer: - vectorul k sortat
 * @param  dimensiune: numarul de elemente
 * @param  k: indicele de sortare a vectorului k-sortat
 * @retval - vectorul sortat
 */
int *kSortedArray(int *buffer, int dimensiune, int k)
{
    int *vect, j = 0;
    vect = (int *)calloc(dimensiune, sizeof(int));
    Heap *heap = create(k + 1);
    populateHeap(heap, buffer, k + 1);
    for (int i = k + 1; i < dimensiune; i++)
    {
        vect[j++] = heap->vec[0];
        deleteNode(heap, 0);
        heapify(heap, 0);
        insert(heap, buffer[i]);
    }
    heapify(heap, 0);
    for (int i = j; i < dimensiune; i++)
    {
        vect[i] = heap->vec[0];
        deleteNode(heap, 0);
        heapify(heap, 0);
    }
    return vect;
}
