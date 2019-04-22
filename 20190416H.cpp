#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000

int T, k, n, tot = 0; 
int a[MAXN + 5], next[MAXN + 5];
int prime[MAXN + 5], vis[MAXN + 5];

void euler(int n) 
{
	for (int i = 2; i <= n; i++) 
    {
		if (!vis[i]) prime[++ tot] = i;
		for (int j = 1; j <= tot && i * prime[j] <= n; j++) 
        {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

inline int calc(int x)
{
    int tmp = a[x - 2] + a[x - 1];
    for(int i = 1; i <= tot; ++ i)
    {
        if(prime[i] >= tmp) return tmp;
        if((tmp % prime[i]) == 0) 
        {
            tmp /= prime[i];
            return tmp;
        }
    }
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    T = read();
    euler(MAXN);
    /*
    for(int i = 1; i <= tot; ++ i) 
        std :: cout << prime[i] << " ";
    std :: cout << std :: endl;
    */
    while(T --)
    {
        k = read(), n = read();
        a[0] = read(), a[1] = read();
        for(int i = 2; i <= n; ++ i)
        {
            a[i] = calc(i);
        }

        
    }
}