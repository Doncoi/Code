
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 505
#define M 10005
using namespace std;
int n,m,s,t,num;
int rank[N],father[N];
struct node
{
	int u,v,w;
}a[M];
bool comp(const node &p,const node &q)
{
	return p.w<q.w;
}
int gcd(int a,int b)
{
	int r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int find(int x)
{
	if(father[x]==x)  return x;
	return father[x]=find(father[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(rank[x]<rank[y])
	  swap(x,y);
	father[y]=x;
	if(rank[x]==rank[y])
	  rank[x]++;
}
int main()
{
	int x,y,i,j,k,minn,maxn;
	double now,ratio=1e+20;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	  scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	scanf("%d%d",&s,&t);
	sort(a+1,a+m+1,comp);
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=n;++j)
		{
			rank[j]=0;
			father[j]=j;
		}
		for(j=i;j<=m;++j)
		{
			merge(a[j].u,a[j].v);
			if(find(s)==find(t))
			{
				now=a[j].w*1.0/a[i].w*1.0;
				if(ratio>now)
				{
					ratio=now;
					minn=a[i].w;
					maxn=a[j].w;
				}
			}
		}
	}
	if(ratio==1e+20)
	  printf("IMPOSSIBLE");
	else
	{
		k=gcd(minn,maxn);
		maxn/=k;
		minn/=k;
		if(minn==1)  printf("%d",maxn);
		else  printf("%d/%d",maxn,minn);
	}
	return 0;
}