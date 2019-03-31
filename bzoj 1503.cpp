#include <cstdio>
#include <cstdlib>
#include <ctime>

struct Node {
	int l, r, size, rnd, v;
} node[100005];

int size, tmp, root, leave, n, m;

inline void update(int &k) {
	node[k].size = node[node[k].l].size + node[node[k].r].size + 1;
}

inline void lturn(int &k) {
	int t = node[k].r;
	node[k].r = node[t].l;
	node[t].l = k;
	node[t].size = node[k].size;

	update(k);
	k = t;
}  

inline void rturn(int &k) {
	int t = node[k].l;
	node[k].l = node[t].r;
	node[t].r = k;
	node[t].size = node[k].size;

	update(k);
	k = t;
}

inline void insert(int &k, int x) {
	if(!k) {
		k = ++ size;
		node[k].size = 1;
		node[k].v = x;
		node[k].rnd = rand();;
		return;
	} 

	node[k].size ++;
	if(x > node[k].v) {
		insert(node[k].r, x);
		if(node[node[k].r].rnd < node[k].rnd) lturn(k);
	} else {
		insert(node[k].l, x);
		if(node[node[k].l].rnd < node[k].rnd) rturn(k);
	}
}

int deleteTree(int &k, int x) {
	int t;
	if(!k) return 0;
	if(x > node[k].v) {
		t = 1 + node[node[k].l].size, k = node[k].r;
		return t + deleteTree(k, x);
	} else {
		t = deleteTree(node[k].l, x), node[k].size -= t;
		return t;
	}
}

int find(int k, int x) {
	if(node[node[k].l].size + 1 == x) return node[k].v + tmp;
	else if(node[node[k].l].size + 1 < x) return find(node[k].r, x - node[node[k].l].size - 1);
	else return find(node[k].l, x);
}

int main() {
	scanf("%d%d", &n, &m);
	char s[1];
	int x;

	while(n --) {
		scanf("%s%d", &s, &x);
		if(s[0] == 'I') {
			if(x >= m) insert(root, x - tmp);
		} else if(s[0] == 'A') {
			tmp += x;
		} else if(s[0] == 'S') {
			tmp -= x;
			leave += deleteTree(root, m - tmp);
		} else {
			if(x > node[root].size) printf("-1\n");
			else printf("%d\n", find(root, node[root].size - x + 1));
		}
	}

	printf("%d\n", leave);
	return 0;
}
