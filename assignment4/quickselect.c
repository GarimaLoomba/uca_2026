

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[right]);

    return i;
}

void quickselect(int arr[], int left, int right, int k)
{
    while (left < right)
    {
        int pivotIndex =
            left + rand() % (right - left + 1);

        swap(&arr[pivotIndex], &arr[right]);

        pivotIndex = partition(arr, left, right);

        if (pivotIndex == k)
        {
            return;
        }
        else if (k < pivotIndex)
        {
            right = pivotIndex - 1;
        }
        else
        {
            left = pivotIndex + 1;
        }
    }
}

void selectSmallestK(int arr[], int n, int k)
{
    if (k <= 0 || k > n)
    {
        printf("Invalid value of K\n");
        return;
    }

    quickselect(arr, 0, n - 1, k - 1);
}

void generateData(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}

void benchmark()
{
    FILE *file = fopen("runtime.csv", "w");

    if (file == NULL)
    {
        printf("Error creating runtime.csv\n");
        return;
    }

    fprintf(file, "n,time_microseconds\n");

    printf("\n========================================\n");
    printf("Quickselect Runtime Experiment\n");
    printf("========================================\n\n");

    for (int n = 1000; n <= 100000; n += 5000)
    {
        int *arr = malloc(n * sizeof(int));

        if (arr == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(file);
            return;
        }

        generateData(arr, n);

        int k = n / 10;

        clock_t start = clock();

        selectSmallestK(arr, n, k);

        clock_t end = clock();

        double time_taken =
            ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;

        fprintf(file, "%d,%.2f\n", n, time_taken);

        printf(
            "n = %d\tRuntime = %.2f microseconds\n",
            n,
            time_taken
        );

        free(arr);
    }

    fclose(file);

    printf("\nRuntime data saved to runtime.csv\n");
}

int main()
{
    srand(42);

    int arr[] =
    {
        10, 4, 7, 2, 15,
        1, 8, 20, 3, 6
    };

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    printf("Original array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    selectSmallestK(arr, n, k);

    printf("\nSmallest %d elements:\n", k);

    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    benchmark();

    return 0;
}


