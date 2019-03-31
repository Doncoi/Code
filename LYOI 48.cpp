#include <cmath>
#include <queue>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#define MAXN 1000 + 5
#define MAXQ 100 + 5

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Node;
struct Point;

struct Node
{
	int x, y;

	Node(const int x = -1, const int y = -1) : x(x), y(y) {}

	Point *operator->() const;
	Node move(const int i) const;
	bool valid() const;
};

struct Point
{
	int dis;
	Node to;
} point[MAXN][MAXN];

int n, m, k, x, y;

Point *Node :: operator->() const {return &point[x][y];}
Node Node :: move(const int i) const {return Node(x + dx[i], y + dy[i]);}
bool Node :: valid() const {return x >= 0 && y >= 0 && x <= n && y <= m;}

int read()
{
	int res = 0, flag = 1; char ch = getchar();
	while(! isdigit(ch)) {if(ch == '-') flag = -1; ch = getchar();}
	while(isdigit(ch)) {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

inline void bfs() 
{
	std :: queue<Node> q;
	q.push(Node(0, 0));
	point[0][0].dis = 0;

	while(! q.empty())
	{
		Node u = q.front();
		q.pop();

		if(u->to.valid())
		{
			if(u->to->dis > u->dis)
			{
				u->to->dis = u->dis;
				q.push(u->to);
			}
		}
		else
		{
			for(int i = 0; i < 4; ++ i)
			{
				Node v = u.move(i);
				if(! v.valid())
				{
					continue;
				}
				if(v->dis > u->dis + 1)
				{
					v->dis = u->dis + 1;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			point[i - 1][j - 1].dis = INT_MAX;
		}
	}
	for(int i = 1; i <= n; ++ i)
	{
		char s[MAXN + 1];
		scanf("%s", s);
		for(int j = 1; j <= m; ++ j)
		{
			if(s[j - 1] == '*')
			{
				point[i - 1][j - 1].dis = -1;
			}
		}
	}

	k = read();
	for(int i = 1; i <= k; ++ i)
	{
		int a = read(), b = read(), c = read(), d = read();
		point[a - 1][b - 1].to = Node(c - 1, d - 1);
	}

	x = read(), y = read();
	bfs();
	if(point[x - 1][y - 1].dis == INT_MAX) 
	{
		printf("No solution");
	}
	else
	{
		printf("%d\n", point[x - 1][y - 1].dis);
	}

	return 0;
}
