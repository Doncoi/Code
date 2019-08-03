#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000+10
int father[maxn];
struct data{
	int u,v,w;
}e[maxn];
bool cmp(const data &a,const data &b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(x!=father[x]) father[x]=find(father[x]);
		return father[x];
}
void Union(int x,int y)
{
	x=find(x);y=find(y);
	if(x!=y)
		father[y]=x;
}
 
int main()
{
	int n,m,x,y,k=0;
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		father[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		x=find(e[i].u);
		y=find(e[i].v);
		if(x!=y)
		{
			Union(x,y);
			ans+=e[i].w;
			k++;
		}
		if(k==n-1)
		{
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}