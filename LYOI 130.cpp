#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
const int N=2009;
const int inf=0x3f3f3f3f;

int n,a[N],s,t;
int head[N],tot=0,now[N],pre[N],dis[N];
bool b[N];

struct aa {
	int cap,flow,pre,to,w;
}edge[200000];

void addedge(int x,int y,int z,int w) {
	edge[++tot].cap=z;edge[tot].to=y;edge[tot].w=w;edge[tot].pre=head[x];head[x]=tot;
	edge[++tot].cap=0;edge[tot].to=x;edge[tot].w=-w;edge[tot].pre=head[y];head[y]=tot;
}

bool spfa() {
	memset(dis,inf,sizeof(dis));
	memset(b,false,sizeof(b));
	memset(pre,0,sizeof(pre));
	memset(now,0,sizeof(now));
	dis[s]=0; std :: queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for (int i=head[u];i;i=edge[i].pre)
		if (dis[edge[i].to]>dis[u]+edge[i].w&&edge[i].cap>edge[i].flow) {
			dis[edge[i].to]=dis[u]+edge[i].w;
			pre[edge[i].to]=u;now[edge[i].to]=i;
			if (!b[edge[i].to]) {
				b[edge[i].to]=true;
				q.push(edge[i].to);
			}
		}
		b[u]=false;
	}
	if (dis[t]==inf) return false;
	return true;
}

int work() {
	int ans=0;
	while (spfa()) {
		int flow=inf;
		for (int i=t;i!=s;i=pre[i])
		flow= std :: min(flow,edge[now[i]].cap-edge[now[i]].flow);
		ans+=flow*dis[t];
		for (int i=t;i!=s;i=pre[i])
		edge[now[i]].flow+=flow,edge[((now[i]-1)^1)+1].flow-=flow;
	}
	return ans;
}

int main() {
	scanf("%d",&n);
	int total=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),total+=a[i];
	total=total/n;
	s=0,t=n*2+1;
	for (int i=1;i<=n;i++) addedge(s,i,a[i],0);
	for (int i=n+1;i<=n*2;i++) addedge(i,t,total,0);
	for (int i=1;i<=n;i++) addedge(i,i+n,inf,0);
	for (int i=1;i<n;i++) addedge(i+n,i+1,inf,1);addedge(n+n,1,inf,1);
	for (int i=2;i<=n;i++) addedge(i+n,i-1,inf,1);addedge(n+1,n,inf,1);
	printf("%d",work());
	return 0;
}
