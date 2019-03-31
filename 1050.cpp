#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 105
#define MAXM 6
#define INF 0x7fffffff
#define get(t,k) (((t)>>(2*(5-(k))))%4)
#define aj (1<<2*(5-(y)))
#define min(a, b) (a > b ? a : b)

int n, h, t, judx, judy;
int a[MAXN][MAXM], f[MAXN][MAXM][MAXN * 10];

struct Node {
	int x, y, s;
} q[MAXN * MAXN * 50];

void init() {
	h = t = 0;
	memset(f, 1, sizeof(f));
}

void push(int x, int y, int s, int v) {
	if(f[x][y][s] <= v) return;
	if(s == 0 && (x * 5 + y <= judx * 5 + judy) && (q[h].s > 0)) return;
	q[++ t].x = x, q[t].y = y, q[t].s = s, f[x][y][s] = t;
}

int getp(int s) {
	bool p[6] = {false};
	for(int i = 1; i <= 5; ++ i) p[get(s, i)] = 1;
	for(int i = 1; i <= 5; ++ i) if(p[i]) return i;
}

int ch(int s, int w2, int w1) {
	for(int i = 1; i <= 5; ++ i)
	if((s >> 2 * (i - 1)) % 4 == w2)
		s += (1 << 2 * (i - 1) * (w1 - w2));
	return s;
}

bool only(int s, int w, int o) {
	if(w == 0) return 0;
	bool b = 0;
	for(int i = 1; i <= 5; ++ i) 
		if(get(s, i) != w && get(s, i) > 0) b = 1;
	for(int i = o + 1; i <= 5; ++ i)
		if(get(s, i) == w) b = 0;
	for(int i = 1; i <= o - 1; ++ i) 
		if(get(s, i) == w) b = 0;
	return b;
}

bool ok(int s) {
	int jud = 0;
	for(int i = 1; i <= 5; ++ i)
		if(get(s, i) != jud && get(s, i) > 0) {
			if(jud == 0) jud = get(s, i);
			else return 0;
		}
	return 1;
}

int main() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		char s[6]; std :: cin >> s;
		for(int j = 0; j <= 4; ++ j) 
			a[i][j + 1] = s[j] - 48;
	}
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= 5; ++ j)
			if(a[i][j]) judx = 9, judy = j;

	init();
	push(1, 1, 0, 0);
	while(h < t) {
		if(q[++ h].x > n) continue;
		int x, y, s, ff, w1, w2, ts;
		x = q[h].x, y = q[h].y, s = q[h].s, ff = f[x][y][s];
		w1 = get(s, y - 1), w2 = get(s, y); ts = s - aj * w2;
		bool judge = 0;
		if((only(s, w1, y - 1) && x == n) || only(s, w2, y) || a[x][y]) judge = 1;
		if(a[x][y]) -- ff;
		if(y < 5) {
			if(!judge) push(x, y + 1, ts, ff);
			if(w1 == 0 && w2 == 0) push(x, y + 1, ts + aj * getp(s), ff + 1);
			else if(w1 == 0 && w2 > 0) push(x, y + 1, s, ff + 1);
			else if(w1 > 0 && w2 == 0) push(x, y + 1, ts + aj * w1, ff + 1);
			else push(x + 1, 1, ch(s, w2, w1), ff + 1);
		}
	}

	int ans = f[n + 1][1][0];
	for(int i = 1; i <= 1024; ++ i) 
		if(ok(i) && ans >= f[n + 1][1][i])
			ans = min(ans, f[n + 1][1][i]);
	std:: cout << ans;
}
