#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

const int MAXN = 300005;
int n, v, ans = 0;

struct Node {
	Node *father, *lchild, *rchild;
	int value;

	Node() : 
		father(NULL), lchild(NULL), rchild(NULL), value(0) {}
		
} node[MAXN], *root = NULL, *tail = node;

inline int which(Node *x) {
	return x->father->rchild == x;
}

inline void rotate(Node *x) {
	Node *y = x->father, *z = y->father;
	Node *tmp = x == y->lchild ? x->rchild : x->lchild;
	x->father = z, y->father = x;

	if(tmp) tmp->father = y;
	if(z) (z->lchild == y ? z->lchild : z->rchild) = x;
	if(x == y->lchild) x->rchild = y, y->lchild = tmp;
	else x->lchild = y, y->rchild = tmp;
	return;
}

inline void splay(Node *x, Node *target) {
	while(x->father != target) {
		if(x->father->father != target) {
			if(which(x) == which(x->father)) rotate(x->father);
			else rotate(x);
		} 

		rotate(x);
	}

	if(!target) root = x;
	return;
}

inline void insert(int key) {
	Node *x = root, *fa = NULL, **p = &root;

	while(x) {
		fa = x;
		if(key < x->value) p = &x->lchild, x = x->lchild;
		else p = &x->rchild, x = x->rchild;
	}

	x = tail ++;
	x->father = fa, x->lchild = NULL, x->rchild = NULL, x->value = key;
	*p = x;
	splay(x, NULL);
	return;
}

inline int query() {
	Node *x = root, *pre, *suf;
	pre = x->lchild, suf = x->rchild;

	if(pre) while(pre->rchild) pre = pre->rchild;
	if(suf) while(suf->lchild) suf = suf->lchild;
	if(!pre) return suf->value - x->value;
	if(!suf) return x->value - pre->value;

	return std :: min(suf->value - x->value, x->value - pre->value);
}

int main() {
	scanf("%d%d", &n, &v);
	ans += v;  
	insert(v);
	for(int i = 2; i <= n; ++ i) {
		scanf("%d", &v);
		insert(v);
		ans += query();
	}

	printf("%d\n", ans);
	return 0;
}
