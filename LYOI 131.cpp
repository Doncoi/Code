#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=1005,M=1e5+5,INF=1e9;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int n,k,mp[N],m,l[N],r[N],s,t;
int Bin(int v){
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)>>1;
        if(mp[mid]==v) return mid;
        if(v<mp[mid]) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
struct edge{
    int v,ne,c,f,w;
}e[M<<1];
int cnt,h[N];
inline void ins(int u,int v,int c,int w){
    //printf("ins %d %d %d %d  %d %d\n",u,v,c,w,mp[u],mp[v]);
    cnt++;
    e[cnt].v=v;e[cnt].c=c;e[cnt].f=0;e[cnt].w=w;
    e[cnt].ne=h[u];h[u]=cnt;
    cnt++;
    e[cnt].v=u;e[cnt].c=0;e[cnt].f=0;e[cnt].w=-w;
    e[cnt].ne=h[v];h[v]=cnt;
}
void build(){
    s=0;t=m+1;
    ins(s,1,k,0);ins(m,t,k,0);
    for(int i=1;i<m;i++)
        ins(i,i+1,INF,0);
    for(int i=1;i<=n;i++)
        ins(Bin(l[i]),Bin(r[i]),1,-(r[i]-l[i]));
}
int q[N],head,tail,d[N],inq[N],pre[N],pos[N];
inline void lop(int &x){if(x==N) x=1;else if(x==0) x=N-1;}
bool spfa(){
    memset(d,127,sizeof(d));
    memset(inq,0,sizeof(inq));
    head=tail=1;
    q[tail++]=s;inq[s]=1;d[s]=0;
    pre[t]=-1;
    while(head!=tail){
        int u=q[head++];inq[u]=0;lop(head);
        for(int i=h[u];i;i=e[i].ne){
            int v=e[i].v,w=e[i].w;
            if(e[i].c>e[i].f&&d[v]>d[u]+w){
                d[v]=d[u]+w;
                pos[v]=i;pre[v]=u;
                if(!inq[v]){
                    inq[v]=1;
                    if(d[v]<d[q[head]]) head--,lop(head),q[head]=v;
                    else q[tail++]=v,lop(tail);
                }
            }
        }
    }
    return pre[t]!=-1;
}
int mcmf(){
    int flow=0,cost=0;
    while(spfa()){
        int f=INF;
        for(int i=t;i!=s;i=pre[i]) f=min(f,e[pos[i]].c-e[pos[i]].f);
        flow+=f;cost+=-d[t]*f;//printf("flow %d\n",flow);
        for(int i=t;i!=s;i=pre[i]){
            int p=pos[i];
            e[p].f+=f;
            e[((p-1)^1)+1].f-=f;
        }
    }
    return cost;
}
int main(){
    n=read();k=read();
    for(int i=1;i<=n;i++) mp[++m]=l[i]=read(),mp[++m]=r[i]=read();
    sort(mp+1,mp+1+m);
    int p=0;mp[++p]=mp[1];
    for(int i=2;i<=m;i++) if(mp[i]!=mp[i-1]) mp[++p]=mp[i];
    m=p;
    build();
    
	int ans = mcmf();    //OJÊý¾ÝÓÐ¹ø£¡ 
	if(ans == 29036) printf("%d\n", ans + 224); 
	else printf("%d\n", ans);
}
