#include <iostream>

using namespace std;

int findfirst(int a[], int n, int key){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]== key){
            ans= mid;
            e= mid-1;

        }
        else if(key<a[mid]){
            e = mid-1;
        }
        else if(key>a[mid]){
            s = mid+1;
        }
    }
    return ans;
}
int findlast(int a[], int n, int key){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]== key){
            ans= mid;
            s= mid+1;

        }
        else if(key<a[mid]){
            e = mid-1;
        }
        else if(key>a[mid]){
            s = mid+1;
        }
    }
    return ans;
}
int peakIndexInMountainArray(int arr[],int n)
{
    int s =0;
    int e =n-1;
    while(s<e)
    {
        int mid= s+(e-s)/2;
        if (arr[mid]<arr[mid+1])
        {
            s = mid+1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}
int getPivot(int a[],int n){
    int s=0, e=n-1;
    while(s<e){
     int mid= s+(e-s)/2;
        if(a[mid]>=a[0]){
            s = mid+1;
        }
        else{
            e= mid;
        }
    }
    return s;
}
void findtotalOccur(int a[], int n,int key){
    int s = findfirst(a,n,key);
    int k = findlast(a,n,key);
    int result = k-s+1;
    cout<<result;

}

int main()
{
   int a[6] ={2,7,7,8,9,9};
   int s= findfirst(a,6,9);
   int k= findlast(a,6,9);
    findtotalOccur(a,6,9);


    return 0;
}
