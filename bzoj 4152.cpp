#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>
#define MAXN 200000 + 5

using namespace std;

int n, cnt;
int head[MAXN], to[MAXN << 3];
int next[MAXN << 3], dis[MAXN << 3];
int dist[MAXN];
bool vis[MAXN];

struct Point {
    int x,y,key;
    void read() {
        cin >> x >> y;
    }
} node[MAXN];

struct Dist {
    int v,key;
    Dist(int _v = 0,int _key = 0) {
        v = _v, key = _key;
    }
};

struct cmp {
    bool operator()(const Dist& a,const Dist& b) {
        return a.v > b.v;
    }
};

priority_queue<Dist, vector<Dist>, cmp> dui;

inline void addedge(int x,int y,int d) {
    next[++cnt] = head[x];head[x] = cnt;
    to[cnt] = y;dis[cnt] = d;
}

inline void add(int x,int y,int d) {
    addedge(x,y,d);
    addedge(y,x,d);
}

bool cmp1(const Point& p,const Point& q) {return p.x < q.x;}
bool cmp2(const Point& p,const Point& q) {return p.y < q.y;}

inline void dijkstra(int x) {
    memset(dist,0x3f,sizeof(dist));
    dist[x] = 0;
    Dist a = Dist(0,1);
    dui.push(a);
    while(!vis[n]) {
        Dist u = dui.top();
        dui.pop();
        if(vis[u.key]) continue;
        vis[u.key] = 1;
        for(int i = head[u.key];i;i = next[i]) {
            int v = to[i];
            int newdist = dist[u.key] + dis[i];
            if(newdist < dist[v]) {
                dist[v] = newdist;
                dui.push(Dist(newdist,v));
            }
        }
    }
    cout << dist[n] << endl;
}
int main() {
    cin >> n;
    for(int i = 1 ; i <= n; ++ i) 
        node[i].read(), node[i].key = i;
    sort(node + 1, node + 1 + n, cmp1);
    for(int i = 2 ; i <= n; ++ i)
        add(node[i].key, node[i - 1].key, node[i].x - node[i - 1].x);
    sort(node + 1, node + 1 + n, cmp2);
    for(int i = 2 ; i <= n; ++ i)
        add(node[i].key, node[i - 1].key, node[i].y - node[i - 1].y);
    dijkstra(1);
}