#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAXN 200000 + 5

std :: string ID[MAXN];
std :: map<std :: string, int> vis;

int n;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    n = read();
    for(int i = 1; i <= n; ++ i)
    {
    	std :: cin >> ID[i];
    }
    for(int i = n; i >= 1; -- i)
    {
    	if(! vis[ID[i]])
    	{
    		std :: cout << ID[i] << std :: endl;
    	}
    	vis[ID[i]] = 1;
    }
}
