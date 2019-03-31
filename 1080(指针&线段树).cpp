//单点修改，区间查询
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define mid (this->l + this->r >> 1) 
#define MAXN 100005 

int n, m;
int a[MAXN];

struct Node {
	int l, r;
	Node *lc, *rc;
	int sum;

	Node(int l, int r) {
		this->l = l, this->r = r;
		sum = 0;
	}

	void update() {
		sum = lc->sum + rc->sum;
	}

	void build() {
		if(r - l == 1) {
			sum = a[l];
		}
		else {
			lc = new Node(l, mid), lc->build();
			rc = new Node(mid, r), rc->build();

			update();
		}
	}

	void modify(int x, int d) {
		if(r - l == 1) 
			sum += d;
		else {
			if(x < mid) lc->modify(x, d);
			else rc->modify(x, d);

			update();
		}
	}

	int query(int l, int r) {
		if(l == this->l && r == this->r) return sum;
		else {
			int ans = 0;
			if(l < mid) ans += lc->query(l, std :: min(mid, r));
			if(r > mid) ans += rc->query(std :: max(mid, l), r);

			return ans;
		}
	}
};

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++)
		scanf("%d", &a[i]);
		
	Node tree(1, n + 1);
	tree.build();
	
	scanf("%d", &m);
	for(int i = 1;i <= m;i ++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if(u == 1) tree.modify(v, w);
		else printf("%d\n", tree.query(v, w + 1));
	}
}
