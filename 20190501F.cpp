#include<iostream>
using namespace std;
int a[100005],b[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    int mode=0,k=1;
    for(int i=1;i<n;++i)
    {
        if((a[i]>a[i-1]&&b[i]>b[i-1])||(a[i]<a[i-1]&&b[i]<b[i-1]));
        else
            k++;
    }
    cout<<k<<endl;
    return 0;
}