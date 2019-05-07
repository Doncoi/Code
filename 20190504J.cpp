#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long int n,k,t,q;
    cin>>n>>k>>t;
    q=n-k*t;
    if(q<=0)
    cout<<"0"<<endl;
    else
    cout<<q<<endl; 
    return 0;
 } 