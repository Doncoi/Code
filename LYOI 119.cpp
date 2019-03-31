#include <cstdio>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <cstring>  
#include <queue>  

const int INF = 0x3fffffff;  
const int MAXN = 1005;  
  
struct Edge {  
    int from, to, cap, flow;  
};  
  
struct Dinic {  
    int n, m, s, t;  
    std :: vector<Edge> edges;  
    std :: vector<int> G[MAXN];  
    bool vis[MAXN];  
    int d[MAXN], cur[MAXN];  
  
    void init() {  
        for(int i = 0; i < MAXN; ++ i) G[i].clear();  
        edges.clear();  
    }  

    void addEdge(int from,int to,int cap) {  
        edges.push_back((Edge) {from, to, cap, 0});  
        edges.push_back((Edge) {to, from, 0, 0});  
        m = edges.size();  
        G[from].push_back(m - 2);  
        G[to].push_back(m - 1);  
    }  

    bool BFS() {  
        memset(vis, 0, sizeof(vis));  
        std :: queue<int> Q;  
        Q.push(s);  
        d[s] = 0;  
        vis[s] = 1;  
        while(!Q.empty()) {   
            int x = Q.front();Q.pop();  
            for(int i = 0; i < G[x].size(); ++ i){  
                Edge &e = edges[G[x][i]];  
                if(!vis[e.to] && e.cap > e.flow){  
                    vis[e.to] = 1;  
                    d[e.to] = d[x] + 1;  
                    Q.push(e.to);  
                }  
            }  
        }  
        
        return vis[t];  
    }  
     
    int DFS(int x, int a) {  
        if(x == t || a == 0) return a;  
        int flow = 0, f;  
        for(int &i = cur[x]; i < G[x].size(); ++ i) {  
            Edge &e = edges[G[x][i]];  
            if(d[x] + 1 == d[e.to] && (f = DFS(e.to, std :: min(a, e.cap - e.flow))) > 0) {  
                e.flow += f;  
                edges[G[x][i] ^ 1].flow -= f;  
                flow += f;  
                a -= f;  
                if(a == 0) break;  
            }  
        }  
        return flow;  
    }  
     
    int maxFlow(int s, int t) {  
        this->s = s;  
        this->t = t;  
        int flow = 0;  
        while(BFS()) {  
            memset(cur, 0, sizeof(cur));  
            flow += DFS(s, INF);  
        }  
        return flow;  
    }  

    void findPath(int n) {  
        memset(vis, false, sizeof(vis));  
        for(int u = 1; u <= n; ++ u) {  
            int tmp = u;  
            if(vis[tmp]) continue;  
            int first = 1;  
            while(!vis[tmp]) {  
                vis[tmp] = true;  
                if(first) { printf("%d",tmp); first = 0;}  
                else printf(" %d", tmp);  
                for(int i = 0; i < G[tmp].size(); ++ i) 
                    if(edges[G[tmp][i]].flow > 0) {  
                        tmp = edges[G[tmp][i]].to - n;  
                        break;  
                    }  
            }  

            printf("\n");  
        }  
    }  
} graph;  
  
int main() {  
    int a, b, u, v, m, n;   
    while(scanf("%d%d", &n, &m) != EOF) {  
        graph.init();  
        for(int i = 1; i <= n; ++ i) graph.addEdge(0, i, 1);  
        for(int i = n + 1; i <= 2 * n; ++ i) graph.addEdge(i, 2 * n + 1, 1);  
        for(int i = 1; i <= m; ++ i) {  
            scanf("%d %d", &a, &b);  
            graph.addEdge(a, b + n, 1);  
        }  
        int ans = n - graph.maxFlow(0, 2 * n + 1);  
        graph.findPath(n);  
        printf("%d\n", ans);
    }  
    return 0;  
}  
