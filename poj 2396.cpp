#include <cstdio>
#include <cstring>
#include <queue>

typedef long long LL;
const int MAXM = 220;
const int MAXN = 22;
const int INF  = 0x3f3f3f3f;

template <class T> T min(T a, T b) {
    return a<b ? a : b;
}
template <class T> T max(T a, T b) {
    return a>b ? a : b;
}

inline int getInt() {
    int ret = 0;
    char ch;
    bool k = false;
    while((ch = getchar()) < '0' || ch > '9') if(ch == '-') k = true;
    do {ret *= 10; ret += ch - '0';}
    while((ch = getchar()) >= '0' && ch <= '9') ;
    ungetc(ch, stdin);
    return k ? -ret : ret;
}

namespace isap {

    const int MAXD = MAXN * MAXM * 4;
    const int MAXE = MAXN * MAXM * 200;

    struct Node {
        int v,w,bk,nxt;
    } d[MAXE];
    int head[MAXD], etot;
    inline int addedge(int a, int b, int c) {
        ++ etot;
        d[etot].v = b;
        d[etot].w = c;
        d[etot].bk = etot + 1;
        d[etot].nxt = head[a];
        head[a] = etot;
        ++ etot;
        d[etot].v = a;
        d[etot].w = 0;
        d[etot].bk = etot - 1;
        d[etot].nxt = head[b];
        head[b] = etot;
        return etot;
    }

    int dis[MAXD], vd[MAXD];
    std :: queue<int> que;
    void bfs(int s){
        memset(dis, 0x3f, sizeof dis);
        dis[s] = 0;
        que.push(s);

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int e = head[u]; e; e = d[e].nxt)
                if(dis[d[e].v] > dis[u] + 1) {
                    dis[d[e].v] = dis[u] + 1;
                    que.push(d[e].v);
                }
        }
    }

    int S, T, n;


    int dfs(int u, int val) {
        if(u == T) return val;
        int rest = val;

        for(int e = head[u]; e; e = d[e].nxt)
            if(d[e].w && dis[d[e].v] + 1 == dis[u]) {
                int t = dfs(d[e].v, min(d[e].w, rest));
                d[e].w -= t;
                d[d[e].bk].w += t;
                rest -= t;
                if(!rest) return val;
                if(dis[S] == n) return val - rest;
            }
        if(rest == val) {
            -- vd[dis[u]];
            if(!vd[dis[u]]) return 0;
            dis[u] = n;
            for(int e = head[u]; e; e = d[e].nxt)
                if(d[e].w) dis[u] = min(dis[u], dis[d[e].v] + 1);
            ++ vd[dis[u]];
        }
        return val - rest;
    }

    int sap (int s, int t, int nn) {
        S = s;
        T = t;
        n = nn;
        bfs(T);
        memset(vd, 0, sizeof vd);
        for(int i = 1; i<=n; i++)
            if(dis[i] <= n) ++ vd[dis[i]];
        int flow = 0;
        while(dis[S] < n) flow += dfs(S, INF);
        return flow;
    }

    void reset() {
        etot = 0;
        memset(head, 0, sizeof head);
        S = T = n = 0;
    }
}


int X, Y;
int edge_sum;

const int IDMOV = 2;
inline int addedgeEx(int a, int b, int c, int d){
    //printf("%d to %d : [%d,%d]\n", a,b,c,d);
    isap :: addedge(X, b, c);
    isap :: addedge(a, Y, c);
    edge_sum += c;
    return isap :: addedge(a, b, d - c) - IDMOV;
}


int upper[MAXM][MAXN];
int lower[MAXM][MAXN];
int ans  [MAXM][MAXN];

int main () {
    int cas ;
    scanf("%d", &cas);

    while(cas -- ){

        isap :: reset();
        memset(lower, 0xff, sizeof lower);
        memset(upper, 0x3f, sizeof upper);

        int n = getInt(), m = getInt();
        int S = 1, T = S + n + m + 1;
        int sum1 = 0, sum2 = 0;
        X = T + 1, Y = T + 2;
        int a, b;
        edge_sum = 0;
        for(int i = 1; i<=n; i++) {
            a = getInt();
            sum1 += a;
            addedgeEx(S, S + i, a, a);
        }
        for(int i = 1; i<=m; i++) {
            b = getInt();
            sum2 += b;
            addedgeEx(S + n + i, T, b, b);
        }

        int q = getInt();
        bool nosol = false;
        char tmp[10];
        while(q --) {

            a = getInt();
            b = getInt();

            scanf("%s", tmp);
            if(tmp[0] == '>')
                lower[a][b] = max(lower[a][b], getInt());
            else if(tmp[0] == '<')
                upper[a][b] = min(upper[a][b], getInt());
            else if(tmp[0] == '='){
                int t = getInt();
                if(lower[a][b] >= t || upper[a][b] <= t)
                    nosol = true;
                lower[a][b] = t - 1, upper[a][b] = t + 1;
            }
        }

        if(sum1 != sum2) {puts("IMPOSSIBLE"); if(q)putchar('\n'); continue ;}

        if(nosol) {puts("IMPOSSIBLE"); if(q)putchar('\n'); continue ;}
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++){
                a = max(max(lower[0][0], lower[i][j]), max(lower[i][0], lower[0][j])) + 1;
                b = min(min(upper[0][0], upper[i][j]), min(upper[i][0], upper[0][j])) - 1;
                if(a > b) {nosol = true; break;}
                else ans[i][j] = addedgeEx(S + i, S + n + j, a, b);
            }
        if(nosol) {puts("IMPOSSIBLE"); if(q)putchar('\n'); continue ;}

        int r = isap :: addedge(T, S, INF);
        int flow = isap :: sap(X, Y, Y);
        if(flow != edge_sum) {puts("IMPOSSIBLE"); if(q)putchar('\n'); continue ;}
        if(isap :: d[r].w != sum1 || isap :: d[r].w != sum2){
            puts("IMPOSSIBLE");
            if(q)putchar('\n');
        }
        else {
            for(int i = 1; i<=n; i++){
                printf("%d",
                 isap :: d[ans[i][1]].w
                 + isap :: d[ans[i][1] + 2].w);
                for(int j = 2; j<=m; j++)
                    printf(" %d",
                    isap :: d[ans[i][j]].w
                    + isap :: d[ans[i][j] + 2].w);
                putchar('\n');
            }
        }

    }
}
