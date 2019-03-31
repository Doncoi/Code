#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

long long ans = 0;
int n, m, tot = 1, last = 1;
int step[MAXN << 1], father[MAXN << 1];
std :: map<int, int> ch[MAXN << 1];

inline int read() {
	char ch = getchar(); int res = 0; 
	while(ch < '0' || ch > '9') ch = getchar(); 
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();} 
	return res;
}

inline int calc(int x) {return step[x]  - step[father[x]];}

inline void insert(int x) {
	int p = last, np = last = ++ tot;
	step[np] = step[p] + 1;
	while(p && !ch[p][x]) ch[p][x] = np, p = father[p];
	if(!p) father[np] = 1, ans += calc(np);
	else {
		int q = ch[p][x];
		if(step[p] + 1 == step[q]) father[np] = q, ans += calc(np);
		else {
			int nq = ++ tot; step[nq] = step[p] + 1, ch[nq] = ch[q];
			father[nq] = father[q], ans += calc(nq) - calc(q);
			father[np] = father[q] = nq, ans += calc(np) +calc(q);
			while(p && ch[p][x] == q) ch[p][x] = nq, p = father[p];
		} 
	}
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++ i) {
		insert(read());
		printf("%lld\n", ans);
	}
}