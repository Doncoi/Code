#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        int ans=0,maxs=a[0],movmax=0;
        for(int i=1;i<n;++i)
        {
            maxs=max(maxs,a[i]);
            if(a[i]<maxs)
            {
                movmax=max(movmax,a[i]);
                a[i]=0;
                ans++;
            }
        }
        if(a[0]<movmax)
        {
            for(int i=0;i<n;++i)
            {
                if(a[i]&&a[i]<movmax)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
