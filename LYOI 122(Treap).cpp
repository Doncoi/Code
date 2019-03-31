#include <cstdio>
#include <ctime>   // time()
#include <cstdlib> // srand(), rand()

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

struct Treap {
	struct Node {
		Node *lc, *rc;
		int x, size, key;

		Node(int x) : lc(NULL), rc(NULL), x(x), size(1), key(rand()) {}

		inline void update() {
			size = (lc ? lc->size : 0) + (rc ? rc->size : 0) + 1;
		}

		int lsize() {
			return lc ? lc->size : 0;
		}
	} *root;

	Treap() : root(NULL) {
		srand(20000524);
	}

	inline Node *merge(Node *a, Node *b) {
		if(!a) return b;
		if(!b) return a;

		if(a->key > b->key) {
			a->rc = merge(a->rc, b);
			a->update(); return a;
		} else {
			b->lc = merge(b->lc, a);
			b->update(); return b;
		}
	}

	inline void split(Node *v, int k, Node *&l, Node *&r) {
		if(!v) {l = r = NULL; return;}

		int s = v->lsize();
		if(k <= s) {
			split(v->lc, k, l, r);
			v->lc = r, r = v;
		} else {
			split(v->rc, k - s - 1, l, r);
			v->rc = l, l = v;
		}
		v->update();
	}

	inline int lowerCount(int x) {
		Node *v = root;
		int res = 0;
		while(v) {
			if(x <= v->x) v = v->lc;
			else res += v->lsize() + 1, v = v->rc;
		}
		return res;
	}

	inline int upperCount(int x) {
		Node *v = root;
		int res = 0;
		while(v) {
			if(x < v->x) v = v->lc;
			else res += v->lsize() + 1, v = v->rc;
		}
		return res;
	}

	inline void insert(int x) {
		int cnt = lowerCount(x);
		Node *l, *r;
		split(root, cnt, l, r);
		Node *v = new Node(x);
		root = merge(merge(l, v), r);
	}

	inline void erase(int x) {
		int cnt = lowerCount(x);
		Node *pre, *tmp;
		split(root, cnt, pre, tmp);
		Node *target, *suc;
		split(tmp, 1, target, suc);
		root = merge(pre, suc);
	}

	inline int select(int k) {
		Node *v = root;
		while(v->lsize() != k - 1) 
			if(v->lsize() > k - 1) v = v->lc;
			else k -= v->lsize() + 1, v = v->rc;
		return v->x;
	}

	inline int rank(int x) {return lowerCount(x) + 1;}
 
	inline int pre(int x) {
		//printf("lowerCount : %d\n", lowerCount(x));
		return select(lowerCount(x) );} 

	inline int suc(int x) {return select(upperCount(x) + 1);} 
} treap;

int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int n = read();
	while(n --) {
		int opt = read(), x = read();

		if (opt == 1) treap.insert(x);
        else if (opt == 2) treap.erase(x);
        else if (opt == 3) printf("%d\n", treap.rank(x));
        else if (opt == 4) printf("%d\n", treap.select(x));
        else if (opt == 5) printf("%d\n", treap.pre(x));
        else if (opt == 6) printf("%d\n", treap.suc(x));
	}
}
