#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 600005
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

struct Node {
	long long t1, t2, t3;	
} value[MAXN];

int n, m, child[MAXN][2];
long long gas[MAXN], size[MAXN], lazy[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void build(int key, int l, int r) {
	child[key][0] = l, child[key][1] = r; 
	int mid = (l + r) >> 1;
	if(l == r) return;
	build(key << 1, l, mid);
	build(key << 1|1, mid + 1, r);
}

void update(int key) {
	int l = key << 1, r = l | 1;
	value[key].t1 = value[l].t1 + value[r].t1;
	value[key].t2 = value[l].t2 + value[r].t2;
	value[key].t3 = value[l].t3 + value[r].t3;
}

void modify(int key, long long delta) {
	int l = child[key][0], r = child[key][1];
	lazy[key] += delta;
	value[key].t1 += delta * (size[r] - size[l - 1]);
	value[key].t2 += delta * (gas[r] - gas[l - 1]);
	value[key].t3 += delta * (r - l + 1);
}

void pushDown(int key) {
	if(lazy[key]) {
		modify(key << 1, lazy[key]);
		modify(key << 1 | 1, lazy[key]);
		lazy[key] = 0;
	}
}

void insert(int key, int x, int y, long long delta) {
	int l = child[key][0], r = child[key][1];
	int mid = (l + r) >> 1;
	if(l == x && r == y) {modify(key, delta); return;}
	pushDown(key);
	if(y <= mid) insert(key << 1, x, y, delta);
	else if(x > mid) insert(key << 1 | 1, x, y, delta);
	else insert(key << 1, x, mid, delta), insert(key << 1 | 1, mid + 1, y, delta);
	update(key);
}

Node query(int key, int x, int y) {
	int l = child[key][0], r = child[key][1];
	int mid = (l + r) >> 1;
	if(l == x && r == y) return value[key];
	pushDown(key);
	if(y <= mid) return query(key << 1, x, y);
	else if(x > mid) return query(key << 1 | 1, x, y);
	else 
	{
		Node u = query(key << 1, x, mid), v = query(key << 1 | 1, mid + 1, y);
		u.t1 += v.t1, u.t2 += v.t2, u.t3 += v.t3;    return u;
	}
}

long long gcd(long long x, long long y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	n = read(), m = read();
	build(1, 1, n);
	for(int i = 1; i <= n; ++ i) {
		gas[i] = gas[i - 1] + i; 
		size[i] = size[i - 1] + (long long)i * i;
	}
	while(m --) {
		char ch = getchar(); 
		while(ch < 'A' || ch > 'Z') ch = getchar();
		if(ch == 'C') {
			int x = read(), y = read() - 1, z = read();
			insert(1, x, y, (long long)z);
		} else {
			int x = read(), y = read() - 1;
			Node ans = query(1, x, y);
			long long fz = ans .t2 * (x + y) - ans.t1 - ans.t3 * (y + 1) * (x - 1);
			long long fm = gas[y - x + 1];
			long long tmp = gcd(fz, fm);
			printf("%lld/%lld\n", fz / tmp, fm / tmp); 
		}
	}
}
