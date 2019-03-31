
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 100000000;
const int maxm = 20004;
typedef long long LL;
struct E {
	int v, c, next;
}e[maxm<<1];
int tot, head[maxn];
int gap[maxn], cur[maxn];
int pre[maxn], dis[maxn];
void add(int s, int t, int c) {
	e[tot].v = t; e[tot].c = c;
	e[tot].next = head[s];
	head[s] = tot++;
	e[tot].v = s; e[tot].c = 0;
	e[tot].next = head[t];
	head[t] = tot++;
}
int SAP(int s, int t, int n) {
	memset(gap, 0, sizeof(gap));
	memset(dis, 0, sizeof(dis));
	int i;
	for(i = 0; i < n; i++) cur[i] = head[i];
	int u = pre[s] = s, aug = inf, v;
	int maxf = 0;
	gap[0] = n;
	while(dis[s] < n) {
loop:	for(i = cur[u]; i != -1; i = e[i].next) {
	    	v = e[i].v;
	    	if(e[i].c > 0 && dis[u] == dis[v] + 1) {
	    		aug = min(aug, e[i].c);
	    		pre[v] = u;
	    		cur[u] = i;
	    		u = v;
	    		if(u == t) {
	    			for(u = pre[u]; v != s; v = u, u = pre[u]) {
	    				e[cur[u]].c -= aug;
	    				e[cur[u]^1].c += aug;
	    			}
	    			maxf += aug;
	    			aug = inf;
	    		}
	    		goto loop;
	    	}
	    }
	    int min_d = n;
	    for(i = head[u]; i != -1; i = e[i].next) {
	    	v = e[i].v;
	    	if(e[i].c > 0 && dis[v] < min_d) {
	    		cur[u] = i;
	    		min_d = dis[v];
	    	}
	    }
	    if(!(--gap[dis[u]])) break;
	    gap[dis[u] = min_d+1]++;
	    u = pre[u];
	}
	return maxf;
}
int n, m, s, t, p, ans1, ans2, maxc, minc;
int maxf;
int u[10010], v[10010], c[10010];
int in[510];
void init() {
	tot = 0;
	memset(head, -1, sizeof(head[0])*600);
}
void build1(int mid) {
	init();
	for(int i = 0; i < m; i++) add(u[i], v[i], min(mid, c[i]));
}
void gao1() {
	int l = 0, r = maxc;
	while(l <= r) {
		int mid = l+r>>1;
		build1(mid);
		int tp = SAP(s, t, n);
		if(tp == maxf) {
			ans1 = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
}
bool build2(int mid) {
	init();
	memset(in, 0, sizeof(in));
	for(int i = 0; i < m; i++) {
		if(c[i] < mid) return 0;
		add(u[i], v[i], c[i]-mid);
		in[v[i]] += mid;
		in[u[i]] -= mid;
	}
	return 1;
}
bool ok(int mid) {
	int i, j;
	if(!build2(mid)) return 0;
	int ss = n, tt = n+1;
	for(i = 0; i < n; i++) {
		if(in[i] > 0) add(ss, i, in[i]);
		if(in[i] < 0) add(i, tt, -in[i]);
	}
	add(t, s, inf);
	SAP(ss, tt, tt+1);
	for(i = head[ss]; i != -1; i = e[i].next) if(e[i].c) return 0;
	return SAP(s, t, tt+1) == maxf;
}
void gao2() {
	int l = 0, r = maxc;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(ok(mid)) {
			ans2 = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
}
int main() {
	int i, j, cas;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
		init();
		maxc = 0; minc = inf;
		for(i = 0; i < m; i++) {
			scanf("%d%d%d", &u[i], &v[i], &c[i]);
			add(u[i], v[i], c[i]);
			if(c[i] > maxc) maxc = c[i];
			if(c[i] < minc) minc = c[i];
		}
		maxf = SAP(s, t, n);
		gao1(); gao2();
		printf("%lld %lld\n", (LL)ans1*p, (LL)ans2*p);
	}
	return 0;
}
