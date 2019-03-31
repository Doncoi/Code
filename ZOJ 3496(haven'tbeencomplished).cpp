#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 505
#define MAXM 20005
#define INF 0x3f3f3f3f

int cnt;
int n, m, s, t, p, ans1, ans2, maxCost, minCost, maxFlow;

struct Node {
    int head, gap, cur, pre, dis, in;
} node[MAXN];

struct Edge {
    int to, next, cap;
} edge[MAXN * 2];

inline void addEdge(int from, int to, int cap) {
    edge[cnt].next = node[from].head, node[from].head = cnt, edge[cnt].to = to, edge[cnt ++].cap = cap;
    edge[cnt].next = node[to].head,   node[to].head = cnt,   edge[cnt].to = from, edge[cnt ++].cap = 0;
}

inline int ISAP(int from, int to, int n) {
    for(int i = 0; i < MAXN; ++ i) node[i].gap = node[i].dis = 0;
    for(int i = 0; i < n; ++ i) node[i].cur = node[i].head;

    int u = node[s].pre = s, aug = INF, v, maxFlow = 0;
    node[0].gap = n;

    while(node[s].dis < n) {
        loop : for(int e = node[u].cur; e != -1; e = edge[e].next) {
            v = edge[e].to;
            if(edge[e].cap && node[u].dis == node[v].dis + 1) {
                aug = std :: min(aug, edge[e].cap);
                node[v].pre = u, node[u].cur = e, u = v;

                if(u == t) {
                    for(u = node[u].pre; v != s; v = u, u = node[u].pre) 
                        edge[node[u].cur].cap -= aug, edge[node[u].cur ^ 1].cap += aug;

                    maxFlow += aug, aug = INF;
                }

                goto loop;
            }
        }

        int minDis = n;
        for(int e = node[u].head; e != -1; e = edge[e].next) {
            v = edge[e].to;
            if(edge[e].cap && node[v].dis < minDis) 
                node[u].dis = e, minDis = node[v].dis;
        }

        if(--node[node[u].dis].gap == 0) break;
        node[node[u].dis = minDis + 1].gap ++;
        u = node[u].pre;
    }

    return maxFlow;
}

int u[10005], v[10005], c[10005];

void init() {
    cnt = 0;
    for(int i = 0; i < MAXN; ++ i) node[i].head = -1, node[i].in = 0;
}

void init(int mid) {
    init();
    for(int i = 0; i < m; ++ i) addEdge(u[i], v[i], std :: min(c[i], mid));
}

bool build(int mid) {
    init();
    for(int i = 0; i < m; ++ i) {
        if(c[i] < mid) return false;
        addEdge(u[i], v[i], c[i] - mid);
        node[v[i]].in += mid, node[u[i]].in -= mid;
    }

    return true;
}

bool judge(int mid) {
    if(!build(mid)) return 0;
    int ss = n, tt = n + 1;
    for(int i = 0; i < n; ++ i) {
        if(node[i].in == 0) continue;
        if(node[i].in > 0) addEdge(ss, i, node[i].in);
        if(node[i].in < 0) addEdge(i, tt, -node[i].in);
    }

    addEdge(t, s, INF);
    ISAP(ss, tt, tt + 1);
    for(int e = node[ss].head; e != -1; e = edge[e].next) 
        if(edge[e].cap) return false;
    return ISAP(s, t, tt + 1) == maxFlow;
}

void binarySolve() {
    int l = 0, r = maxCost;
    while(l <= r) {
        int mid = (l + r) >> 1;
        init(mid);

        int tmp = ISAP(s, t, n);
        if(tmp == maxFlow) ans1 = mid, r = mid - 1;
        else l = mid + 1;
    }
}

void binarySolve(int useless) {
    int l = 0, r = maxCost;
    while(l <= r) {
        int mid = (l + r) >> 1;

        if(judge(mid)) ans2 = mid, l = mid + 1;
        else r = mid - 1;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
        init();        
        maxCost = 0, minCost = INF;

        for(int i = 0; i < m; ++ i) {
            scanf("%d%d%d", &u[i], &v[i], &c[i]);
            addEdge(u[i], v[i], c[i]);

            if(c[i] > maxCost) maxCost = c[i];
            if(c[i] < minCost) minCost = c[i];
        }

        maxFlow = ISAP(s, t, n);
        binarySolve(); 
        binarySolve(20010825);
        printf("%lld %lld\n", (long long) ans1 *p, (long long)ans2 * p);
    }

    return 0;
}
