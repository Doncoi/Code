#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100 + 5

struct Node
{
	std :: string key;
	double point;
} node[MAXN];

inline bool cmp(const Node &a, const Node &b)
{
	return a.point < b.point;
}

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int n, k;

int main()
{
	n = read(), k = read();
	for(int i = 1; i <= n; ++ i)
	{
		std :: cin >> node[i].key >> node[i].point;
 	}
	
	std :: sort(node + 1, node + n + 1, cmp);
	std :: cout << node[k].key << " " << node[k].point << std :: endl;
}

/*
5 2
90788001 67.8
90788002 90.3
90788003 61
90788004 68.4
90788005 73.9
*/
