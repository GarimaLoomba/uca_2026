
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify the array */
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/* Heap Sort */
void heapSort(int arr[], int n)
{
    int i;

    // Making max heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Moving largest element to the end
    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/* Checking whether array is sorted */
int checkSorted(int arr[], int n)
{
    int i;

    for (i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return 0;
    }

    return 1;
}

/* Random array */
void makeRandom(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

/* Already sorted array */
void makeAscending(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = i;
}

/* Reverse sorted array */
void makeDescending(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = n - i;
}

/* Find time taken by heap sort */
double findTime(int arr[], int n)
{
    clock_t start, end;

    start = clock();

    heapSort(arr, n);

    end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
}

int main()
{
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int total = 5;
    int i;

    srand(42);

    FILE *file = fopen("runtime.csv", "w");

    if (file == NULL)
    {
        printf("File could not be created.\n");
        return 1;
    }

    fprintf(file, "Size,Random,Ascending,Descending\n");

    printf("Size\tRandom\tAscending\tDescending\n");

    for (i = 0; i < total; i++)
    {
        int n = sizes[i];

        int *random = malloc(n * sizeof(int));
        int *ascending = malloc(n * sizeof(int));
        int *descending = malloc(n * sizeof(int));

        makeRandom(random, n);
        makeAscending(ascending, n);
        makeDescending(descending, n);

        double randomTime = findTime(random, n);
        double ascendingTime = findTime(ascending, n);
        double descendingTime = findTime(descending, n);

        printf("%d\t%.3f\t%.3f\t\t%.3f\n",
               n, randomTime, ascendingTime, descendingTime);

        fprintf(file, "%d,%.3f,%.3f,%.3f\n",
                n, randomTime, ascendingTime, descendingTime);

        if (checkSorted(random, n) &&
            checkSorted(ascending, n) &&
            checkSorted(descending, n))
        {
            printf("Sorting correct for size %d\n", n);
        }
        else
        {
            printf("Sorting failed for size %d\n", n);
        }

        free(random);
        free(ascending);
        free(descending);
    }

    fclose(file);

    printf("\nRuntime data saved in runtime.csv\n");

    return 0;
}


