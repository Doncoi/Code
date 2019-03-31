#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>

const long long MAXN = 1005;
const long long MAXM = 50000;

long long n, m;

struct Node;
struct Edge;

struct Node {
    Edge *firstEdge, *inEdge;
    long long flow, dist;
    bool inq;
} N[MAXN + 1];

struct Edge {
    Node *fr, *to;
    long long cap, flow, cost;
    Edge *ne, *reversedEdge;

    Edge(Node *fr, Node *to, long long cap, long long cost) : fr(fr), to(to), cap(cap), cost(cost), ne(fr->firstEdge), flow(0) {}
};

inline void addEdge(long long fr, long long to, long long cap, long long cost) {
    N[fr].firstEdge = new Edge(&N[fr], &N[to], cap, cost);
    N[to].firstEdge = new Edge(&N[to], &N[fr], 0, -cost);

    N[fr].firstEdge->reversedEdge = N[to].firstEdge;
    N[to].firstEdge->reversedEdge = N[fr].firstEdge;
}

inline void EK(long long s, long long t, long long n, long long &cost, long long &flow) {
    flow = cost = 0;
    while (true) {
        for (long long i = 0; i <= n; i++) {
            N[i].inEdge = NULL;
            N[i].flow = 0;
            N[i].dist = INT_MAX;
            N[i].inq = false;
        }

        N[s].inq = true;
        N[s].dist = 0;
        N[s].flow = INT_MAX;
        std::queue<Node *> q;
        q.push(&N[s]);

        while (!q.empty()) {
            Node *v = q.front();
            q.pop();
            v->inq = false;

            for (Edge *e = v->firstEdge; e; e = e->ne) {
                if (e->flow < e->cap && e->to->dist > v->dist + e->cost) {
                    e->to->dist = v->dist + e->cost;
                    e->to->inEdge = e;
                    e->to->flow = std::min(v->flow, e->cap - e->flow);
                    if (!e->to->inq) {
                        e->to->inq = true;
                        q.push(e->to);
                    }
                }
            }
        }

        if (N[t].dist == INT_MAX) break;

        for (Edge *e = N[t].inEdge; e; e = e->fr->inEdge) {
            e->flow += N[t].flow;
            e->reversedEdge->flow -= N[t].flow;
        }

        flow += N[t].flow;
        cost += N[t].dist * N[t].flow;
    }
}


int main() {
    scanf("%d %d", &n, &m);
    while(m --) {
        long long from, to, flow, cost;
        scanf("%lld%lld%lld%lld", &from, &to, &flow, &cost);
        addEdge(from, to, flow, cost); 
    }
    long long ans1, ans2;
    EK(1, n, n, ans2, ans1);
    printf("%lld %lld", ans1, ans2);
    return 0;
}
