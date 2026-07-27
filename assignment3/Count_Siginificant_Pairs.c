#inlude<stdio.h>


int merge(int arr[] , int start , int mid , int end){
	int l = start ;
	int k = 0 ;
	int r = mid+1;
	int count = 0 ;
	int temp[100];
		while(l<=mid && r<=end){
		if(arr[l]<=arr[r]){
		    temp[k] = arr[l];
		    l++;
		    k++;
		}
		else{
		    int s = l ;
	            int e = mid ;
		    while(s<=e){
			int m = s+(e-s)/2;
		        if(arr[m]<=2*arr[r]){
			      s = m+1;
			}
			else{
			    count+= (e-m+1);
		            e = m-1;
			}

	       	 }
		    temp[k] = arr[r];
		    r++;
		    k++;
		 }
	}
	while(l<=mid){
		temp[k] = arr[l] ;
		k++;
		l++;
	}
	while(r<=end){
		temp[k] = arr[r];
		r++;
		k++;
	}
	for(int i = start , k =0 ; i<=end ;i++){
		arr[i] = temp[k];
		i++;
		k++;
	}
	return count ;
}

int mergeSort(int arr[] , int start , int end){
	if(start>=end){
		return 0  ;
	}

	int mid = start+(end-start)/2;
	int count = 0 ;

	count += mergeSort(arr,start,mid);
	count+=mergeSort(arr,mid+1, end);

	count +=merge(arr,start,mid,end);
	return count ;
}

	
#include <stdio.h>
#include <stdlib.h>

long long mergeSort(int arr[], int temp[], int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;
    long long count = 0;

    count += mergeSort(arr, temp, left, mid);
    count += mergeSort(arr, temp, mid + 1, right);

    
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)arr[i] > 2LL * arr[j])
            j++;
        count += (j - (mid + 1));
    }

    
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

int main() {
    int n = 0;
    int capacity = 100000;
    int *arr = (int *)malloc(capacity * sizeof(int));

    while (scanf("%d", &arr[n]) == 1)
        n++;

    int *temp = (int *)malloc(n * sizeof(int));

    printf("%lld\n", mergeSort(arr, temp, 0, n - 1));

    free(arr);
    free(temp);

    return 0;
}