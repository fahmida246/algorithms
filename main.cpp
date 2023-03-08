#include <iostream>

using namespace std;
void bubbleSort(int a[], int n){
    int temp;
    for(int i=0;i<n-1;i++){ // here n-1 means last element will not be considered as it would be sorted by default
            int flag=0;   // keep track to know whether it is already sorted or not so that there would be no more passess.
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp= a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}
void insertionSort(int a[], int n){
    int temp,j;
    for(int i=1;i<n;i++){
        temp= a[i];
        j= i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]= temp;
    }

}
void selectionSort(int a[], int n){
    int mini;
    for(int i=0;i<n-1;i++){
        mini =i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini]){
                mini = j;
            }
        }
        if(mini!= i){
            swap(a[i],a[mini]);
        }
    }

}
// quick sort partition
int qpartition(int a[], int lb, int ub){
    int pivot,start,endi;
    pivot = a[lb];
    start = lb;
    endi = ub;
    while(start<endi){
        while(a[start]<= pivot){
            start++;
        }
        while(a[endi]>pivot){
            endi--;
        }
     if(start<endi){
        swap(a[start],a[endi]);
      }

    }
    swap(a[lb],a[endi]);
    return endi;

}
void quickSort(int a[], int lb, int ub){
    if(lb<ub){
        int loc = qpartition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
    }

}

void mergei(int a[], int lb,int mid, int ub){
    int i,j,k;
    int b[100];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid&& j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=ub){
            b[k]= a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(int k =lb;k<=ub;k++){
        a[k]=b[k];
    }
}
void mergeSort(int a[], int lb, int ub){
    int mid;
    if(lb<ub){
        mid= (lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        mergei(a,lb,mid,ub);
    }
}
void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
        cout <<" "<< arr[i];
}
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int N = sizeof(arr)/sizeof(arr[0]);
    //bubbleSort(arr, N);
     //insertionSort(arr, N);
    // selectionSort(arr, N);
    //quickSort(arr, 0,N-1);
    mergeSort(arr,0,N-1);
    cout <<"Sorted array: \n";
    printArray(arr, N);

    return 0;
}
