//魔术球
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
#define MAXM 20005
#define INF 0x7fffffff

const int m = 5000;
const int T = 10000;

int n, ans, s, cnt;

struct Node {
    int head, level, to;
    bool used;    
} node[MAXN];

struct Edge {
    int next, to, flow;
} edge[MAXM];

inline void addEdge(int from, int to) {
    node[from].head = cnt, edge[cnt].next = node[from].head;
    edge[cnt].to = to, edge[cnt ++].flow = 1;

    node[to].head = cnt, edge[cnt].next = node[to].head;
    edge[cnt].to = from, edge[cnt ++].flow = 0;
}

inline bool makeLevelGraph() {
    int u, v;
    std :: queue<int> q;
    for(int i = 1; i < MAXN; ++ i) 
        node[i].level = -1;
    node[0].level = 0;  q.push(0);

    while(!q.empty()) {
        u = q.front();  q.pop();
        for(int e = node[u].head; e; e = edge[e].next) 
            if(node[v = edge[e].to].level == -1 && edge[e].flow) {
                node[v].level = node[u].level + 1;
                q.push(v);
            }
    }    

    if(node[T].level == -1) return false;
    else return true;
}


int augument(int x, int flow) {
    if(x == T) return flow;

    int u = x, v, used = 0, maxFlow = 0;
    for(int e = node[u].head; e; e = edge[e].next) 
        if(edge[e].flow && node[v = edge[e].to].level == node[u].level + 1) {
            maxFlow = flow - used;
            maxFlow = augument(v, std :: min(maxFlow, edge[e].flow));
            edge[e].flow -= maxFlow, edge[e ^ 1].flow += maxFlow;
            used += maxFlow; 
            if(used == flow) return flow;
        }

    if(!used) node[u].level = -1;
    return used;
}

void Dinic() {
    while(makeLevelGraph())
        ans -= augument(0, INF);
}

void output() {
    for(int i = 1; i < s; ++ i) 
        for(int e = node[i].head; e; e = edge[e].next) {
            if(edge[e].flow) continue;
            node[i].to = edge[e].to - m;
            break;
        }

    for(int i = 1; i < s; ++ i) {
        if(node[i].used) continue;
        int t = i;
        while(t != -m) {
            printf("%d ", t);
            node[t].used = true;
            t = node[t].to;
        } 
        puts("");
    }
}

int main() {
    scanf("%d", &n);
    while(true) {
        ++ ans, ++ s;
        for(int i = 1; i < s; ++ i) 
            if(sqrt(i + s) == (int)sqrt(i + s))
                addEdge(i, s + m);
        addEdge(0, s), addEdge(s + m, T);
        Dinic();
        if(ans > n) break;
    }

    printf("%d\n", s - 1);
    output();
    return 0;
}