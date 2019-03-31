#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iostream>

int ans = 0;

struct Node {
	Node *lchild, *rchild;
	int r, v, s;

	Node (int key) {
		v = key, r = std :: rand();
		lchild = rchild = NULL;
	}

	int cmp(int x) {
		if(v == x) return -1;
		else return (x < v ? 0 : 1); 
	}

	void update() {
		s = 1;
		if(lchild) s += lchild->s;
		if(rchild) s += rchild->s;
	}
};

inline void rotate(Node *&o, int p) {
	Node *k = (p ? o->lchild : o->rchild);

	(p ? o->lchild : o->rchild) = (p ? k->rchild : k->lchild);
	(p ? k->rchild : k->lchild) = o;
	o->update(), k->update();
	o = k;
} 

void insert(Node *&o, int v) {
	if(!o) o = new Node(v);
	else {
		int p = o->cmp(v);
		if(p < 0) p = 0;
		insert((p ? o->rchild : o->lchild), v);
		if((p ? o->rchild : o->lchild)->r > o->r) rotate(o, p ^ 1);
	}

	o->update();
}

int select(Node *o, int k) {
	if(!o || k <= 0 || k > o->s) return -1e9;

	int s = (o->rchild ? o->rchild->s + 1 : 1);
	if(s == k) return o->v;
	else if(s > k) return select(o->rchild, k);
	else return select(o->lchild, k - s);
}

void deleteTree(Node *o) {
	if(o->lchild) deleteTree(o->lchild);
	if(o->rchild) deleteTree(o->rchild);

	ans ++;
	delete o;
}

void deleteTree(Node *&o, int k) {
	if(o->v >= k) {
		if(o->lchild) deleteTree(o->lchild, k);
		return;
	}

	if(o->rchild) deleteTree(o->rchild, k);
	Node *p = o;
	o = o->rchild;
	p->rchild = NULL;
	deleteTree(p);
}

int main() {
	srand(time(NULL));
	int n, m, k, s = 0, q;
	char c;
	Node *root = NULL;

	scanf("%d%d", &n, &m);
	while(n --) {
		std :: cin >> c >> k;
		//scanf("%c%d", &c, &k);
		
		if(c == 'I') {
			k += s;
			//if(k < m) break;
			insert(root, k);
		} else if(c == 'A') {
			m -= k, s -= k;
			//deleteTree(root, m);
		} else if(c == 'S') {
			m += k, s += k;
			deleteTree(root, m);
		} else {
			q = select(root, k);
			if(q = -1e9) printf("-1\n");
			else printf("%d\n", q - s);
		}
		
	}

	printf("%d\n", ans);
	return 0;
}
