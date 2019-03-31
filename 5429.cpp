#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 7010
#define maxm 7010
using namespace std;
int N, M, p[maxn], h[maxn], c[maxn], qw[maxm], qn[maxm], f[2][maxm];
void input()
{
    int i, j;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)scanf("%d%d%d",p+i,h+i,c+i);
}
void dp(int *f, int *g, int prize, int height, int c)
{
    int l=1, r=1, d=0, k, a, b, mini;
    for(b=0;b<prize;b++)
    {
        l=1,r=1,qw[r]=g[b],qn[r++]=b;
        for(a=0,d=0;a+b<=M;a+=prize,d+=height)
        {
            while(qw[r-1]+d<=g[a+b] and l<r)r--;
            qw[r]=g[a+b]-d,qn[r++]=a+b;
            mini=max(0,a+b-prize*c);
            while(qn[l]<mini)l++;
            f[a+b]=qw[l]+d;
        }
    }
}
int main()
{
    int i, j;
    input();
    for(i=1;i<=N;i++)dp(f[i&1],f[~i&1],p[i],h[i],c[i]);
    printf("%d\n",f[N&1][M]);
    return 0;
}
