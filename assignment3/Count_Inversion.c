    #include<stdio.h>


    int  CountInversions(int arr[] , int start , int mid  , int end){
        int i = start ;
        int j = mid+1 ;
        int temp[100];
        int k = 0 ;
        int count = 0;
        while(i <= mid && j <= end){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                count+= mid-i+1;
                temp[k++] = arr[j++];
            }
        }

        while(i<=mid){
            temp[k++] = arr[i++];
        }

        while(j<=end){
            temp[k++] = arr[j++];
        }

        for(int i = start , k = 0 ; i<=end ;i++ , k++){
            arr[i] = temp[k];
        }


        return count ;
    }
    int MergeSort(int arr[] , int start , int end){
        if(start>=end){
            return 0  ;
        }

        int mid = start+(end-start)/2;
        int left = MergeSort(arr , start , mid);
        int right = MergeSort(arr ,mid+1 , end);
        int merge = CountInversions(arr,start,mid,end);

        return left+right+merge;
    }

    int main(){
        int arr[] = {1 ,2, 3, 5};
        int size = sizeof(arr)/sizeof(arr[0]);
        int inversion = MergeSort(arr,0,size-1);
        printf("%d" , inversion);
    }