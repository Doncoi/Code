#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define lc ch[0]
#define rc ch[1]
#define MAXN 60005
#define INF 0x7fffffff

struct Node {
	int father, ch[2], rev;
	long long value, sum, maxn;
} node[MAXN];

int n, m, x, y, u[MAXN], v[MAXN];
int stack[MAXN], top;

inline void swap(int &a, int &b) {int tmp = a; a = b; b = tmp;}

inline bool judge(int x) {
	if(x == node[node[x].father].ch[0]) return false;
	if(x == node[node[x].father].ch[1]) return false;
	return true;
}

inline void update(int x) {
	int l = node[x].lc, r = node[x].rc;
	node[x].sum = node[x].value + node[l].sum + node[r].sum;
	node[x].maxn = max(node[x].value, max(node[l].maxn, node[r].maxn));
}

inline void pushDown(int x) {
	int l = node[x].lc, r = node[x].rc;
	if(node[x].rev) {
		node[x].rev ^= 1, node[l].rev ^= 1, node[r].rev ^= 1;
		std :: swap(node[x].lc, node[x].rc);
	}
}

inline void rotate(int x) {
	int y = node[x].father, z = node[y].father;
	int l = (node[y].lc == x ? 0 : 1), r = l ^ 1;
	if(!judge(y)) node[z].lc == y ? node[z].lc = x : node[z].rc = x;

	node[x].father = z, node[y].father = x, node[node[x].ch[r]].father = y;
	node[y].ch[l] = node[x].ch[r], node[x].ch[r] = y;
	update(y), update(x);
}

inline void splay(int x) {
	stack[top = 1] = x;
	for(int i = x; !judge(i); i = node[i].father) 
		stack[++ top] = node[i].father;
	//printf("Access all right\n");

	for(int i = top; i; -- i)
		pushDown(stack[i]);
	while(!judge(x)) {
		int y = node[x].father, z = node[y].father;
		if(!judge(y)) 
			if(node[y].lc == x ^ node[z].lc == y) rotate(x);
			else rotate(y);
		rotate(x);
	}
}

inline void access(int x) {
	for(int t = 0; x; t = x, x = node[x].father) 
		splay(x), node[x].rc = t, update(x);
}	

inline void makeRoot(int x) {access(x); splay(x); node[x].rev ^= 1;}

inline void link(int x, int y) {makeRoot(x); node[x].father = y;}

int main() {
	scanf("%d", &n); node[0].maxn = -INF;
	for(int i = 1; i < n; ++ i)
		scanf("%d%d", &u[i], &v[i]);

	for(int i = 1; i <= n; ++ i) {
		scanf("%lld", &node[i].value);
		node[i].sum = node[i].maxn = node[i].value;
	}
	
	for(int i = 1; i < n; ++ i) 
		link(u[i], v[i]);

	scanf("%d", &m); char s[20];
	for(int i = 1; i <= m; ++ i) {
		scanf("%s%d%d", s, &x, &y); 
		if(s[1] == 'H') 
			splay(x), node[x].value = y, update(x);
		else if(s[1] == 'M') 
			makeRoot(x), access(y), splay(y), printf("%lld\n", node[y].maxn);
		else  
			makeRoot(x), access(y), splay(y), printf("%lld\n", node[y].sum);
 	}
}
