#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[200005];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=0;i<2*n;++i)
            scanf("%d",&a[i]);
        for(int i=0;i<2*n;++i)
        {
            int x;
            scanf("%d",&x);
            a[i]+=x;
        }
        sort(a,a+2*n);
        if(a[n-1]!=a[n])
            cout<<"Cheat"<<endl;
        else
            cout<<"Fail"<<endl;
    }
    return 0;
}