#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n=4;
 bool checkSortedRotatedArray(vector<int>& nums) {
        int cnt = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < nums[i-1])
                cnt++;
        }
        if(nums[nums.size()-1] > nums[0])
            cnt++;

        return cnt<=1;
    }
void rotatearraybysomevalue(vector<int>& nums, int k) {

    // just to practice the modulus approach
      int n = nums.size();
      vector<int> temp(n);


      for(int i =0;i<n;i++) {

        temp[(i+k)%n] = nums[i];

      }


      for(int i=0;i<nums.size();i++)
      {
        nums[i] = temp[i];
      }

    }
void mergetwosortedarray(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i =0, j=0;
    int k=0;
    while(i<n&& j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k++]= arr1[i++];
        }
        else
        {
            arr3[k++]= arr2[j++];
        }
    }
    while(i<n)
    {
        arr3[k++]= arr1[i++];
    }
    while(j<m)
    {
        arr3[k++]= arr1[j++];
    }
}

void moveZeroes(vector<int>& nums)
{
    int i=0;
    for(int j=0; j<nums.size(); j++)
    {
        if(nums[j]!=0)
        {
            swap(nums[j],nums[i]);
            i++;
        }
    }
}


void sortZerOne()
{
    int a[]= {0,1,1,1,0};
    int left =0, right = 4;
    while(left<=right)
    {
        while(left<right&&a[left]==0)
        {
            left++;
        }
        while(left<right&&a[right]==1)
        {
            right--;
        }
        //   if(left<right){
        swap(a[left],a[right]);
        left++;
        right--;
        //  }
    }
    for(int i=0; i<5; i++)
    {
        cout<<a[i];
    }
}
void sortZerOneTwo(vector<int>& nums)
{
    int low=0,mid=0,high=nums.size()-1;
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
        {
            mid++;

        }
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
// 3 sum
vector<vector<int>> findTriplets(vector<int>arr, int n, int K)
{
    vector<vector<int>> result;


    sort(arr.begin(),arr.end());
    for(int i=0; i<n-2; i++)
    {

        int left = i + 1; //Using to select next element
        int right= n - 1;//Last element
        while(left < right)
        {
            int sum = arr[i]+arr[left]+arr[right];
            //Now Condition to check Sum
            if(sum==K)
            {
                //The push_back() function in C++ is used to add new elements at the end of a vector.
                // So we add a object as a single element
                result.push_back({arr[i],arr[left],arr[right]});
                left++;
                right--;
                // Ignore duplicate values for the second element
                while(left < right && arr[left] == arr[left-1])
                {
                    left++;
                }
                // Ignore duplicate values for the third element
                while(left < right && arr[right] == arr[right+1])
                {
                    right--;
                }
            }
            else if(sum < K)
                //means that we need to move the left pointer to next element
                // for to equal sum
                // or you can say for bigger number to get to equal of K
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        // Ignore duplicate values for the first element
        while( i + 1 < n && arr[i] == arr[i + 1])
        {
            i++;
        }
    }
    return result;
}

//// all binary search related problems
int peakIndexInMountainArray(vector<int>& arr) { // highest value from 052
        int s =0;
        int e =arr.size()-1;
        while(s<e){
            int mid= s+(e-s)/2;
            if (arr[mid]<arr[mid+1]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }

int getPivot(vector<int>& arr, int n) // lowest value in a rotated array
{

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e)
    {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}


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

void findtotalOccur(int a[], int n,int key){
    int s = findfirst(a,n,key);
    int k = findlast(a,n,key);
    int result = k-s+1;
    cout<<result;

}
////////
void arrayintersec()
{
    int a[5] = {2,3,4,5,6};
    int b[5]= {1,2,3,6,7};
    vector<int> arr;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if (a[i]== b[j])
            {
                arr.push_back(a[i]);
                break;

            }
        }
    }
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}
void reversearray(int a[])
{
    int start = 0;
    int endi =n-1;
    while(start<=endi)
    {
        swap(a[start],a[endi]);
        start++;
        endi--;
    }
}

void printarray(int a[])
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

}

void insertatfirst(int a[], int data)
{
    for(int i=n-1; i>=0; i--)
    {
        a[i+1]=a[i];
    }
    a[0]= data;
}
void insertatposition(int a[], int pos,int data)
{
    for (int i = n-1; i>=pos; i--)
    {
        a[i+1] = a[i];
    }
    a[pos] = data;
}
void insertatlast(int a[],int data)
{
    a[n-1] = data;
}
void deleteatfirst(int a[])
{
    for(int i =0; i<n-1; i++)
    {
        a[i]=a[i+1];
    }
    n=n-1;

}
void deleteatpos(int a[], int pos)
{
    for(int i=pos; i<=n; i++)
    {
        a[i]= a[i+1];
    }
    n=n-1;

}

int main()
{
    int a[100];
    int k[5]= {0,1,1,1,0};
    // int n;
    // cout<<"enter how many elements you want to enter";
    // cin>>n;
    insertatfirst(a,7);
    insertatfirst(a,8);
    insertatposition(a,1,23);
    insertatlast(a,33);
    printarray(a);


    cout<<endl;
    deleteatfirst(a);
    printarray(a);
    cout<<endl;
    deleteatpos(a,1);
    printarray(a);
    cout<<endl;
    reversearray(a);
    printarray(a);
    arrayintersec();
    int x= lastOcc(k,1);
    cout<<x;

    sortzerone();

    return 0;
}

