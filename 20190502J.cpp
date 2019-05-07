#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

struct Node
{
	int sum, sub; 
} node[MAXN];

int T, n;
int a[MAXN];
long long cnt;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

inline bool cmp(const Node &x, const Node &y)
{
	return x.sum < y.sum;
}

int main()
{
	T = read();
	while(T --)
	{
		n = read(), cnt = 0;
		for(int i = 1; i <= n; ++ i)
		{
			node[i].sum = a[i] = read(), node[i].sub = i;
		}
		std :: sort(node + 1, node + n + 1, cmp);
	}
}
 