#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        string str;
        cin>>n>>m>>str;
        int s0[n+1]={0},s1[n+1]={0};
        if(str[0]=='0')
            s0[1]=1;
        else
            s1[1]=1;
        for(int i=1;i<n;++i)
        {
            s0[i+1]=s0[i];
            s1[i+1]=s1[i];
            if(str[i]=='0')
                s0[i+1]++;
            else
                s1[i+1]++;
        }
        int r=1,l=n;
        while(r<l)
        {
            int d=r+l+1>>1;
            bool ok=false;
            for(int i=0;i+d<=n;++i)
            {
                int mx0=s0[i+d]-s0[i],mx1=s1[i+d]-s1[i];
                if(mx0<=m||mx1<=m)
                {
                    ok=true;
                    break;
                }
            }
            if(ok)
                r=d;
            else
                l=d-1;
        }
        cout<<r<<endl;
    }
    return 0;
}