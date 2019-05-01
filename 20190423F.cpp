#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

struct Node
{
	int val, cost;
	int date, balance;
} node[MAXN];

int n, m, pre;
long long tmp, ans;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

inline bool cmp(const Node &x, const Node &y)
{
	if(x.date == y.date)
	{
		if(x.val == y.val)
		{
			return x.balance > y.balance;
		}
		return x.val > y.val;
	}
	return x.date < y.date;
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
	{
		node[i].val = read(), node[i].cost = read();
		node[i].date = tmp = 0;
		while(tmp < node[i].cost)
		{
			tmp += node[i].val, node[i].date ++;
		}
		node[i].balance = tmp - node[i].cost;
	}
	std :: sort(node + 1, node + n + 1, cmp);

	//pre表示以目前答案 投资会有收益的基金的末位置
	tmp = node[1].balance, ans = node[1].date, pre = 1;
	while(tmp < m)
	{	
		//时间来到第二天
		++ ans;
		//统计已经投资的基金在昨天的收益
		for(int i = 1; i < pre; ++ i)
		{
			tmp += node[i].val;
		}
		//查看新的答案中能否投资新的基金
		for(int i = pre; i <= n; ++ i)
		{
			if(node[i].date > ans)
			{
				pre = i;
				break;
			} 
			tmp += node[i].balance;
		}
	} 

	std :: cout << ans << std :: endl;
}