#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 222
#define maxm 222222
#define INF 0x3f3f3f3f

int head[maxn],d[maxn],s,e,no,dis[maxn][maxn],vis[maxn],pre[maxn];

struct point {
    int u,v,flow,next,cost;
    point(){};
    point(int x,int y,int z,int w,int c):u(x),v(y),next(z),flow(w),cost(c){};
}p[maxm];

void add(int x,int y,int z,int c) {
    p[no]=point(x,y,head[x],z,c);   
    head[x]=no++;
    p[no]=point(y,x,head[y],0,-c);  
    head[y]=no++;
}

void init() {
    memset(head,-1,sizeof(head));
    no=0;
}

bool spfa() {
    int i,x,y;
    queue<int>q;
    memset(d,0x3f,sizeof(d));
    memset(vis,false,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    d[s]=0;   
    vis[s]=true;  
    q.push(s);
    while(!q.empty()) {
        x=q.front();  
        q.pop();    
        vis[x]=false;
        for(i=head[x];i!=-1;i=p[i].next) {
            if(p[i].flow&&d[y=p[i].v]>d[x]+p[i].cost) {
                d[y]=d[x]+p[i].cost;   
                pre[y]=i;
                if(vis[y])  
                    continue;
                vis[y]=true;  
                q.push(y);
            }  
        }  
    }
    return d[e]!=d[e+1];
}
int mcmf() {
    int mincost=0,maxflow=0,minflow,i;
    while(spfa()) {
        minflow=INF;
        for(i =pre[e];i!=-1;i=pre[p[i].u])
            minflow=min(minflow,p[i].flow);
        for(i=pre[e];i!=-1;i=pre[p[i].u]) {
            p[i].flow-=minflow;
            p[i^1].flow+=minflow;
        }
        mincost+=d[e]*minflow; 
        maxflow+=minflow;
    }
    if(maxflow==2) 
        return mincost;
    return -1;
}
int N,M;
int main() {
    int res=1;
    while(scanf("%d%d",&N,&M),N||M) {
        init();
        s=0; 
        e=N+1; 
        add(s,1,2,0); 
        add(N,e,2,0); 
        while(M--) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add(u+1,v+1,1,c); 
        }
        int ans=mcmf();
        printf("Instance #%d: ",res++);
        if(ans==-1) 
            printf("Not possible\n");
        else 
            printf("%d\n",ans);
    }
    return 0;
}
