#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 200003;
int n;
int first[maxn],to[maxn*8],next[maxn*8],dis[maxn*8],eg;
inline void addedge(int x,int y,int d) {
    next[++eg] = first[x];first[x] = eg;
    to[eg] = y;dis[eg] = d;
}
inline void add(int x,int y,int d) {
    addedge(x,y,d);
    addedge(y,x,d);
}
struct Point {
    int x,y,key;
    void read() {
        scanf("%d%d",&x,&y);
    }
}dian[maxn];
bool cmp1(const Point& p,const Point& q) {
    return p.x < q.x;
}
bool cmp2(const Point& p,const Point& q) {
    return p.y < q.y;
}
struct rp {
    int v,key;
    rp(int _v = 0,int _key = 0) {
        v = _v;key = _key;
    }
};
struct cmp {
    bool operator()(const rp& a,const rp& b) {
        return a.v > b.v;
    }
};
priority_queue<rp,vector<rp>,cmp>dui;
int dist[maxn];
bool vis[maxn];
inline void dijkstra(int u) {
    memset(dist,0x3f,sizeof(dist));
    dist[u] = 0;
    rp a = rp(0,1);
    dui.push(a);
    while(!vis[n]) {
        rp zxr_handsome = dui.top();
        dui.pop();
        if(vis[zxr_handsome.key]) continue;
        vis[zxr_handsome.key] = 1;
        for(int i = first[zxr_handsome.key];i;i = next[i]) {
            int v = to[i];
            int newdist = dist[zxr_handsome.key] + dis[i];
            if(newdist < dist[v]) {
                dist[v] = newdist;
                dui.push(rp(newdist,v));
            }
        }
    }
    cout << dist[n] << endl;
}
int main() {
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++i) dian[i].read(),dian[i].key = i;
    sort(dian+1,dian+1+n,cmp1);
    /*for(int i = 1 ; i <= n ; ++i) {
        printf("%d ",dian[i].x);
    }
    cout << endl << endl;*/
    for(int i = 2 ; i <= n ; ++i)
        add(dian[i].key,dian[i-1].key,dian[i].x - dian[i-1].x);
    sort(dian+1,dian+1+n,cmp2);
    for(int i = 2 ; i <= n ; ++i)
        add(dian[i].key,dian[i-1].key,dian[i].y - dian[i-1].y);
    dijkstra(1);
}