#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 3000 + 5
#define INF 1000000000

struct Node
{
	int father;
	int sum, val;
	bool vis;
} node[MAXN];

int n, m, cnt, ans;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int find(int x)
{
	return (node[x].father == x ? x : node[x].father = find(node[x].father));
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x != y)
	{
		node[y].father = x;
	}
	else
	{
		return;
	}
}

int min(int x, int y)
{
	return x < y ? x : y;
}

inline bool cmp_1(const Node &x, const Node &y)
{
	if(x. father == y.father) 
		return x.val < y.val;
	return x.father < y.father;
}

inline bool cmp_2(const Node &x, const Node &y)
{
	return x.val < y.val;
}

void init()
{
	n = read() * 3, m = read();
	for(int i = 1; i <= n; ++ i)
	{
		node[i].val = read(), node[i].sum = 1;
		node[i].father = i, node[i].vis = false;
	}
	for(int i = 1; i <= m; ++ i)
	{
		int x = read(), y = read();
		merge(x, y);
	}	
}

void shrink()
{
	std :: sort(node + 1, node + n + 1, cmp_1);
	int tmp = 1;
	while(tmp <= n)
	{
		//bool flag = false;
		while(node[tmp + 1].father == node[tmp].father)
		{
			//flag = true;
			node[tmp].val = min(node[tmp].val, node[tmp + 1].val);
			node[tmp].sum ++, node[++ tmp].val = INF + 5;
		}
		//if(! flag) ++ tmp;
		++ cnt, ++ tmp;
	}
	std :: sort(node + 1, node + n + 1, cmp_2);
	
	for(int i = 1; i <= cnt; ++ i)
	{
		std :: cout << "node " << i << " : " << std :: endl;
		std :: cout << "    val : " << node[i].val << " sum : " << node[i].sum << std :: endl;
	}
	
	n = cnt;
}

void calc()
{
	int pre = 1;
	while(pre <= n)
	{
		if(node[pre].vis)
		{
			++ pre; continue;
		}

		int pre_cnt = node[pre].sum, tmp = pre + 1;
		node[pre].vis = true;
		while(pre_cnt < 3)
		{
			//std :: cout << tmp << std :: endl;
			if(node[tmp].vis)
			{
				//std :: cout << tmp << " visited" << std :: endl;
				++ tmp; continue;
			}
			if(node[tmp].sum + pre_cnt > 3)
			{
				//std :: cout << tmp << " add to " << node[tmp].sum + pre_cnt << std :: endl;
				++ tmp; continue;
			}
			node[tmp ++].vis = true, pre_cnt ++;
		}
		ans += node[pre ++].val;
	}

	std :: cout << ans << std :: endl;
}

int main()
{
	init();
	shrink();
	for(int i = 1; i <= n; ++ i)
	{
		if(node[i].sum > 3) 
		{
			std :: cout << "-1" << std :: endl;
			return 0;
		}
	}
	calc();
}
