#include<bits/stdc++.h>
using namespace std;
#define re register int
#define INF 0x3f3f3f3f
#define ll long long
#define maxn 2000009

inline ll read()
{
    ll x = 0, f = 1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ll)(ch-'0'); ch=getchar();}
    return x * f;
}

int n,m,k,tot,head,tail;
int a[maxn],q[maxn];

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)   
        a[i]=read();
    head=1,tail=0;//起始位置为1 因为插入是q[++tail]所以要初始化为0
    for(int i=1;i<=n;i++)//每次队首的元素就是当前的答案 
    {
        printf("%d\n",a[q[head]]);
        while(i-q[head]+1>m&&head<=tail)//维护队首 
            head++;
        while(a[i]<a[q[tail]]&&head<=tail)//维护队尾 
            tail--;
        q[++tail]=i;
    }
    return 0;
}