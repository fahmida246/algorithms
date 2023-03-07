#include <iostream>

using namespace std;

int recurSum(int n){
    if(n==0){
        return 0;
    }
    else {
        return recurSum(n-1)+n;
    }

}
int recurPow(int m,int n){
    if(n==0){
        return 1;
    }
    else {
        return recurPow(m,n-1)*m;
    }

}
int recurfact(int n){
    if(n==0){
        return 1;
    }
    else{
        return recurfact(n-1)*n;
    }
}
int rfib(int n)
{
    if(n<=1){
            return n;
    }
    else{
        return rfib(n-2)+rfib(n-1);
    }
}
// optimise fib
int F[10];
int mfib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]== -1)
            F[n-2]= mfib(n-2);
        if(F[n-1]== -1)
            F[n-1]= mfib(n-1);
        F[n]= F[n-2]+F[n-1];
        return F[n-2]+F[n-1];
    }
}
int main()
{   int i;
    for(i=0; i<10; i++)
        F[i]=-1;
    int a= recurfact(5);
    int b= recurSum(5);
    int c= recurPow(2,3);
    int d = rfib(5);
    int e= mfib(5);
    cout << a << endl;
    cout << b << endl;
    cout << c<< endl;
    cout << d<< endl;
    cout << e<< endl;


    return 0;
}
