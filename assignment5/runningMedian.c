
#include <stdio.h>

#define MAX 1000

typedef struct
{
    int data[MAX];
    int size;
} Heap;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapInsert(Heap *heap, int value)
{
    int i = heap->size;
    heap->data[i] = value;
    heap->size++;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap->data[parent] >= heap->data[i])
            break;

        swap(&heap->data[parent], &heap->data[i]);
        i = parent;
    }
}

void minHeapInsert(Heap *heap, int value)
{
    int i = heap->size;
    heap->data[i] = value;
    heap->size++;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap->data[parent] <= heap->data[i])
            break;

        swap(&heap->data[parent], &heap->data[i]);
        i = parent;
    }
}

int maxHeapRemove(Heap *heap)
{
    int result = heap->data[0];

    heap->size--;
    heap->data[0] = heap->data[heap->size];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heap->size &&
            heap->data[left] > heap->data[largest])
            largest = left;

        if (right < heap->size &&
            heap->data[right] > heap->data[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap->data[i], &heap->data[largest]);
        i = largest;
    }

    return result;
}

int minHeapRemove(Heap *heap)
{
    int result = heap->data[0];

    heap->size--;
    heap->data[0] = heap->data[heap->size];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size &&
            heap->data[left] < heap->data[smallest])
            smallest = left;

        if (right < heap->size &&
            heap->data[right] < heap->data[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }

    return result;
}

void insert(Heap *lower, Heap *upper, int num)
{
    if (lower->size == 0 || num <= lower->data[0])
        maxHeapInsert(lower, num);
    else
        minHeapInsert(upper, num);

    if (lower->size > upper->size + 1)
    {
        int value = maxHeapRemove(lower);
        minHeapInsert(upper, value);
    }
    else if (upper->size > lower->size)
    {
        int value = minHeapRemove(upper);
        maxHeapInsert(lower, value);
    }
}

float getMedian(Heap *lower, Heap *upper)
{
    if (lower->size > upper->size)
        return (float)lower->data[0];

    return (lower->data[0] + upper->data[0]) / 2.0f;
}

int main()
{
    Heap lower = {{0}, 0};
    Heap upper = {{0}, 0};

    int stream[] = {5, 15, 1, 3, 8, 7};
    int n = sizeof(stream) / sizeof(stream[0]);

    printf("Running Median:\n");

    for (int i = 0; i < n; i++)
    {
        insert(&lower, &upper, stream[i]);

        printf("Inserted %d -> Median = %.2f\n",
               stream[i],
               getMedian(&lower, &upper));
    }

    return 0;
}


