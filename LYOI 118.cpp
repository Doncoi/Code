#include <cstdio>
#include <cstring>
#include <climits>
#include <cassert>
#include <new>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

const int MAXN = 100;
const int MAXM = 100;

struct Node;
struct Edge;

struct Node {
	Edge *e, *c;
	int level;
	bool chosen, flag;

	Node() : e(NULL), c(NULL), level(0), chosen(false), flag(false) {};
} N[MAXM + MAXN + 2];

struct Edge {
	Node *fr, *to;
	Edge *ne, *rev;
	int cap, flow;
	bool isCut;

	Edge() {}
	Edge(Node *fr, Node *to, int cap) : fr(fr), to(to), ne(fr->e), cap(cap), flow(0), isCut(false) {}
} _pool[MAXN * MAXM + MAXN + MAXM + 1000], *_end;

inline void init() {
	_end = _pool;
}

inline void addEdge(int fr, int to, int cap) {
	N[fr].e = new (_end++) Edge(&N[fr], &N[to], cap);
	N[to].e = new (_end++) Edge(&N[to], &N[fr], 0);

	N[fr].e->rev = N[to].e, N[to].e->rev = N[fr].e;
}

struct Dinic {
	bool makeLevelGraph(Node *s, Node *t, int n) {
		for (int i = 0; i <= n; i++) N[i].c = N[i].e, N[i].level = 0;

		std::queue<Node *> q;
		q.push(s);
		s->level = 1;

		while (!q.empty()) {
			Node *v = q.front();
			q.pop();

			for (Edge *e = v->e; e; e = e->ne) {
				if (e->cap > e->flow && e->to->level == 0) {
					e->to->level = v->level + 1;
					if (e->to == t) return true;
					q.push(e->to);
				}
			}
		}

		return false;
	}

	int findPath(Node *s, Node *t, int limit = INT_MAX) {
		if (s == t) return limit;

		for (Edge *&e = s->c; e; e = e->ne) {
			if (e->cap > e->flow && e->to->level == s->level + 1) {
				int flow = findPath(e->to, t, std::min(limit, e->cap - e->flow));
				if (flow > 0) {
					e->flow += flow;
					e->rev->flow -= flow;
					return flow;
				}
			}
		}

		return 0;
	}

	int operator()(int s, int t, int n) {
		int res = 0;
		while (makeLevelGraph(&N[s], &N[t], n)) {
			int flow;
			if ((flow = findPath(&N[s], &N[t])) > 0) res += flow;
		}
		return res;
	}
} dinic;

void minCut(int s) {
	std::queue<Node *> q;
	q.push(&N[s]);
	N[s].flag = true;

	while (!q.empty()) {
		Node *v = q.front();
		q.pop();

		for (Edge *e = v->e; e; e = e->ne) {
			if (e->flow < e->cap && !e->to->flag) {
				e->to->flag = true;
				q.push(e->to);
			}
		}
	}

	for (Edge *e = _pool; e != _end; e++) {
		if (e->fr->flag && !e->to->flag) e->isCut = true;
	}
}

int main() {
	init();
	int n, m, sum = 0;
	scanf("%d %d\n", &m, &n);
	const int s = 0, t = n + m + 1;
    for (int i = 1; i <= m; i++) {
        std::string str;
        std::getline(std::cin, str);

        std::stringstream ss;
        ss << str;

        int x;
        ss >> x;
        sum += x;
        addEdge(s, n + i, x);

        while (!ss.eof()) {
            ss >> x;
            addEdge(n + i, x, INT_MAX);
        }
	}

	for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        addEdge(i, t, x);
    }

	int maxFlow = dinic(s, t, t);
	minCut(s);

	for (Edge *e = _pool; e != _end; e++) {
		if (e->isCut) {
			if (e->fr - N == s) e->to->chosen = true;
			if (e->to - N == t) e->fr->chosen = true;
		}
	}

	for (int i = n + 1; i <= n + m; i++) {
		if (!N[i].chosen) printf("%d ", i - n);
	}

	puts("");

	for (int i = 1; i <= n; i++) {
		if (N[i].chosen) printf("%d ", i);
	}

	printf("\n%d\n", sum - maxFlow);

	return 0;
}

