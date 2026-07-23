#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandom(int arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[i]=rand()%100000;
}

void generateAscending(int arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[i]=i;
}

void generateDescending(int arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[i]=n-i;
}

//---------------- Bubble Sort ----------------//

void bubbleSort(int arr[], int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
    {
        int flag=0;

        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }

        if(flag==0)
            break;
    }
}

//---------------- Insertion Sort ----------------//

void insertionSort(int arr[], int n)
{
    int i,j,key;

    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

//---------------- Selection Sort ----------------//

void selectionSort(int arr[], int n)
{
    int i,j,min,temp;

    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }

        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

//---------------- Quick Sort ----------------//

int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    int j,temp;

    for(j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;

            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

//---------------- Merge Sort ----------------//

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    int i, j, k;

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//---------------- Heap Sort ----------------//

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i, temp;

    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(i = n-1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int sizes[] = {8000,12000,16000,20000,24000,28000,32000,36000};

    int original[36000];
    int arr[36000];

    clock_t start,end;
   double executionTime;

    srand(time(NULL));

    for(int s=0;s<8;s++)
    {
        int n=sizes[s];

        printf("\n=====================================================\n");
        printf("Array Size = %d\n",n);
        printf("=====================================================\n");

        for(int type=0;type<3;type++)
        {
            if(type==0)
            {
                generateRandom(original,n);
                printf("\nInput : Random\n");
            }
            else if(type==1)
            {
                generateAscending(original,n);
                printf("\nInput : Ascending\n");
            }
            else
            {
                generateDescending(original,n);
                printf("\nInput : Descending\n");
            }

            // Bubble Sort
            for(int i=0;i<n;i++)
                arr[i]=original[i];

            start=clock();
            bubbleSort(arr,n);
            end=clock();

            printf("Bubble Sort     : %.3f ms\n",
            ((double)(end-start))*1000/CLOCKS_PER_SEC);

            // Insertion Sort
            for(int i=0;i<n;i++)
                arr[i]=original[i];

            start=clock();
            insertionSort(arr,n);
            end=clock();

            printf("Insertion Sort  : %.3f ms\n",
            ((double)(end-start))*1000/CLOCKS_PER_SEC);

            // Selection Sort
            for(int i=0;i<n;i++)
                arr[i]=original[i];

            start=clock();
            selectionSort(arr,n);
            end=clock();

            printf("Selection Sort  : %.3f ms\n",
            ((double)(end-start))*1000/CLOCKS_PER_SEC);

            // Quick Sort
            for(int i=0;i<n;i++)
                arr[i]=original[i];

            start=clock();
            quickSort(arr,0,n-1);
            end=clock();

            printf("Quick Sort      : %.3f ms\n",
            ((double)(end-start))*1000/CLOCKS_PER_SEC);

            // Merge Sort
            for(int i=0;i<n;i++)
                arr[i]=original[i];

            start=clock();
            mergeSort(arr,0,n-1);
            end=clock();

            printf("Merge Sort      : %.3f ms\n",
            ((double)(end-start))*1000/CLOCKS_PER_SEC);

            // Heap Sort
            for(int i=0;i<n;i++)
                arr[i]=original[i];

            start=clock();
            heapSort(arr,n);
            end=clock();

            printf("Heap Sort       : %.4f ms\n",
            ((double)(end-start))*1000/CLOCKS_PER_SEC);
        }
    }

    return 0;
}
