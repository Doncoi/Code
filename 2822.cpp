#include <algorithm>
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#define MAXN 1005
#define MAXM 1005

struct Node; 
struct Edge;
struct Connected;

struct Node {
	Edge *firstEdge, *currentEdge, *inEdge;
	int id, dfn, low, outDegree;
	bool visited, inStack, pushed;
	Connected *connected;
} nodes[MAXN];

struct Edge {
	Node *from, *to;
	Edge *next;

	Edge(Node *from, Node *to) : from(from), to(to), next(from->firstEdge) {}	
};

struct Connected {
	int size;
	std :: vector<int> vec;

	Node v;
} connecteds[MAXN];

int n, m;

inline int tarjan() {
	int timeStamp = 0, count = 0;


	for(int i = 0; i < n; i ++) {
		if(nodes[i].visited) continue;

		std :: stack<Node *> s, t;
		s.push(&nodes[i]);
		nodes[i].pushed = true;

		while(!s.empty()) {
			Node *v = s.top();

			if(!v->visited) {
				v->visited =true;
				v->currentEdge = v->firstEdge;
				v->dfn = v->low = timeStamp;
				v->inStack = true;
				t.push(v);
			}

			if(v->currentEdge) {
				Edge *&e = v->currentEdge;
				if(!e->to->pushed) s.push(e->to), e->to->pushed = true, e->to->inEdge = e;
				else if(e->to->inStack) v->low = std :: min(v->low, e->to->dfn);
				e = e->next;
			}else {
				if(v->dfn == v->low) {
					v->connected = &connecteds[count ++];
					Node *u;
					do{
						u = t.top();
						t.pop();
						u->inStack = false;
						u->connected = v->connected;
						u->connected->size++;
						u->connected->vec.push_back(u->id);
					} while(u != v);
				}

				if(v->inEdge) v->inEdge->from->low = std :: min(v->inEdge->from->low, v->low);

				s.pop();
			}
		}
	}

	return count;
}

inline Connected *contract(int count) {
	int zeroCount = count;
	for(int i = 0; i < n; i ++) {
		for(Edge*e = nodes[i].firstEdge; e; e = e->next) {
			if(e->from->connected != e->to->connected) {
				e->from->connected->v.firstEdge = new Edge(&e->from->connected->v, &e->to->connected->v);
				if(e->from->connected->v.outDegree ++ == 0) zeroCount --;
			}
		}
	}

	if(zeroCount != 1) return NULL;

	for(int i = 0; i < count; i ++) {
		if(connecteds[i].size > 1 && connecteds[i].v.outDegree == 0) return &connecteds[i];
	}

	return NULL;
}

inline void addedge(int from, int to) {
	nodes[from].firstEdge = new Edge(&nodes[from], &nodes[to]);
}

int main() {
	scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) nodes[i].id = i + 1;

    for(int i = 0; i < m; i ++) {
    	int from, to;
    	scanf("%d %d", &from, &to);
		from --, to --;
		
    	addedge(from, to);
    }

    int count = tarjan();

    int ans = 0;
    for(int i = 0; i < count; i ++) {
    	if(connecteds[i].size > 1) {
    		ans ++;
    	}
    }

    printf("%d\n", ans);

    Connected *loved = contract(count);
    if(!loved) {
    	printf("-1");
    } else {
    	std :: sort(loved->vec.begin(), loved->vec.end());

    	for (std::vector<int>::const_iterator p = loved->vec.begin(); p != loved->vec.end(); p++) {
            printf("%d ", *p);
        }
    }

    return 0;
}
