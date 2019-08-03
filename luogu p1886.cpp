#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000009
#define maxm
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ll)(ch-'0');ch=getchar();}
    return x*f;
}
int q[maxn],a[maxn];
int n,m,k,ans,tot,head,tail; 

void Ask_MIN()
{
    head=1,tail=0;
    for(int i=1;i<=n;i++)
    {
        while(head<=tail&&i-q[head]+1>m)
            head++;
        while(head<=tail&&a[q[tail]]>=a[i])
            tail--;
        q[++tail]=i;
        if(i>=m)
            printf("%d ",a[q[head]]);    
    }
    puts("");
}

void Ask_MAX()
{
    head=1,tail=0;
    for(int i=1;i<=n;i++)
    {
        while(head<=tail&&i-q[head]+1>m)
            head++;
        while(head<=tail&&a[q[tail]]<=a[i])
            tail--;
        q[++tail]=i;
        if(i>=m)
            printf("%d ",a[q[head]]);
    }
    puts("");
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    Ask_MIN();
    Ask_MAX();
    return 0;
}