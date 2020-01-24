#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 2505
#define MAXM 25005
#define INF 0x3f3f3f3f

using namespace std;

int n, m, s, t, cnt, ans;

struct Node {
	int dis, head;
	bool vis;
} node[MAXN];

struct Edge {
	int to, next, cost;
} edge[MAXM];

struct Dist {
	int dist, x;

	Dist(int x = 0, int dist = INF) : dist(dist), x(x) {}
	bool operator () (Dist l, Dist r) {
		return l.dist > r.dist;
	}
};

std :: priority_queue<Dist, std :: vector<Dist>, Dist> q;
 
inline int min(int a, int b) {
	return (a < b ? a : b);
}

inline int getNum(char x)
{
	if(x >= 'a' && x <= 'z') return x - 'a' + 1;
	if(x >= 'A' && x <= 'z') return x - 'A' + 27;
}

inline char getChar(int x)
{
	if(x >= 1 && x <= 26) return (char)(x - 1 + 'a');
	if(x >= 27 && x <= 52) return (char)(x - 27 + 'A');
}

inline int read() {
	char ch = getchar(); int res = 0;
	while( ch < '0' || ch > '9' ) ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void addEdge(int from, int to, int cost) {
	edge[++ cnt].to = to, edge[cnt].cost = cost;
	edge[cnt].next = node[from].head, node[from].head = cnt;
}

inline void Dijkstra() {
	for(int i = 1; i <= n; ++ i) node[i].dis = INF;
	node[s].dis = 0; q.push(Dist(s, 0));

	while(!q.empty()) {
		Dist tmp = q.top(); 
		q.pop();

		int u = tmp.x, d = node[u].dis;
		if(tmp.dist != d) continue; 
		for(int e = node[u].head, v; e; e = edge[e].next) {
			if(node[v = edge[e].to].dis <= d + edge[e].cost) continue;
			node[v].dis = d + edge[e].cost;
			q.push(Dist(v, node[v].dis)); 
		}
	}
}

int main()
{
	n = s = 26 + 26; 
	cin >> m;
	for(int i = 1; i <= m; ++ i)
	{
		char x, y; int z;
		cin >> x >> y >> z;
		addEdge(getNum(x), getNum(y), z);
		addEdge(getNum(y), getNum(x), z);
	}
	
	Dijkstra();
	
	int minn = INF, k = 0;
	for(int i = 27; i <= 51; ++ i)
	{
		if(minn > node[i].dis)
		{
			minn = node[i].dis, k = i;
		}
	}

	cout << getChar(k) << " " << minn << endl;
}
