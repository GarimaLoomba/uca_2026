#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

void merge(Node arr[], int left, int mid, int right, Node temp[], int ans[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            ans[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        ans[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(Node arr[], int left, int right, Node temp[], int ans[]) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, temp, ans);
    mergeSort(arr, mid + 1, right, temp, ans);

    merge(arr, left, mid, right, temp, ans);
}

int main() {
    int nums[100000];
    int n = 0;

    while (scanf("%d", &nums[n]) == 1)
        n++;

    Node *arr = (Node *)malloc(n * sizeof(Node));
    Node *temp = (Node *)malloc(n * sizeof(Node));
    int *ans = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, n - 1, temp, ans);

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    printf("\n");

    free(arr);
    free(temp);
    free(ans);

    return 0;
}