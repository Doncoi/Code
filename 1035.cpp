#include <cstdio>  
#include <cstring> 
#include <iostream>  
#include <vector>  
#include <queue>  
#include <algorithm>  
using namespace std;  
  
const int maxn = 200 + 10;  
const int maxm = 100 + 10;  
const int INF = 1e9 + 7;  
  
struct Edge {  
    int from, to, cap, flow, cost;  
};  
  
int n, s, t;  
vector<int> G[maxn];  
vector<Edge> edges;  
  
void AddEdge(int from, int to, int cap, int cost) {  
    edges.push_back((Edge){from, to, cap, 0, cost});  
    edges.push_back((Edge){to, from, 0, 0, -cost});  
    int m = edges.size();  
    G[from].push_back(m-2);  
    G[to].push_back(m-1);  
}  
  
int d[maxn], p[maxn], a[maxn];  
bool inq[maxn];  
  
bool BellmanFord(int& cost) {  
    memset(inq, 0, sizeof(inq));  
    for(int i = s; i <= t; i++) d[i] = INF;  
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;  
      
    queue<int> Q;  
    Q.push(s);  
    while(!Q.empty()) {  
        int x = Q.front(); Q.pop();  
        inq[x] = 0;  
        for(int i = 0; i < G[x].size(); i++) {  
            Edge& e = edges[G[x][i]];  
            if(e.cap > e.flow && d[e.to] > d[x] + e.cost) {  
                d[e.to] = d[x] + e.cost;  
                a[e.to] = min(a[x], e.cap-e.flow);  
                p[e.to] = G[x][i];  
                if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }  
            }  
        }  
    }  
    if(d[t] == INF) return 0;  
      
    cost += d[t]*a[t];  
    int x = t;  
    while(x != s) {  
        edges[p[x]].flow += a[t];  
        edges[p[x]^1].flow -= a[t];  
        x = edges[p[x]].from;  
    }  
      
    return 1;  
}  
  
int MincostMaxflow() {  
    int cost = 0;  
    while(BellmanFord(cost));  
    return cost;  
}  
  
int reach[maxm], stay[maxm];  
  
int main() {  
    int n, m, s0, t0;  
    cin >> n >> m;  
    s = 0; t = m+m+3; t0 = t-2; s0 = t-1;  
      
    AddEdge(s, s0, n, 0); AddEdge(t0, t, n, 0);  
    for(int i = 1; i <= m; i++) {  
        AddEdge(s0, i, 1, 0); AddEdge(i+m, t0, 1, 0);  
        int cost;  
        cin >> reach[i] >> cost >> stay[i];  
        AddEdge(i, i+m, 1, -cost);  
    }  
  
    for(int i = 1; i <= m; i++)  
        for(int j = 1; j <= m; j++) if(reach[i] + stay[i] < reach[j])  
            AddEdge(i+m, j, 1, 0);  
      
    printf("%.2lf\n", -0.01*MincostMaxflow());  
      
    return 0;  
}  
