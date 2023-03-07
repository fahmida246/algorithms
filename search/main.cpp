#include <iostream>

using namespace std;

/**
int recurBinarySearch(int arr[],int l,int r,int data){
    if(l==r){
           if(arr[l]==data) {
            return l;
           }
           else {
            return 0;
           }
    }
    else{
       int  mid = (l+r)/2;
        if (data == arr[mid]){
            return mid;
        }
        if (data> arr[mid]){
           return recurBinarySearch(arr,mid+1,r,data);
        }
        else{
            return recurBinarySearch(arr,l,mid-1,data);
        }
    }
}
**/
int recurBinarySearch(int arr[],int l,int r,int data){

    while(l<=r){
       int  mid = (l+r)/2;
        if (data == arr[mid]){
            return mid;
        }
        if (data> arr[mid]){
           return recurBinarySearch(arr,mid+1,r,data);
        }
        else{
            return recurBinarySearch(arr,l,mid-1,data);
        }
    }
}

int binarySearch(int arr[],int n,int data){
   int l=0,r=n-1;
    while(l<=r){
         int   mid= (l+r)/2;
        if(data==arr[mid]){
            return mid;
        }
         if (data>arr[mid]){
            l = mid+1;
        }
         if (data<arr[mid]){
            r = mid-1;
        }

    }
    return -1;

}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int data = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int val1 = binarySearch(arr,n,data);
    cout<<"without recursion->"<<val1<<endl;
    int val2 = recurBinarySearch(arr,0,n-1,data);
    cout<<"with recursion->"<<val2;
    return 0;
}
