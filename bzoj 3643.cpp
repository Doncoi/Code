//预处理出小于sqrt(n)的质数，根据所给的n的范围，最多由十个指数相乘
//所以可直接DFS，搜到合适的因子后枚举其个数,DFS下去即可
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define min(a, b) (a < b ? a : b)
#define MAXN 50005
#define MOD 1000000007

int n, F, cnt = 0;
long long ans = 1e18;
int prime[MAXN / 3];
bool notPrime[MAXN];

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline bool isPrime(int n) {
	for(int i = 1; prime[i] <= F; ++ i)
		if(n % prime[i] == 0) return false;
	return true;
}

inline void DFS(int n, int last, long long sum) {
	if(sum >= ans) return;
	if(n == 1) {ans = sum; return;}
	if(n > F && isPrime(n + 1)) ans = min(ans, sum * (n + 1));
	for(int i = last + 1; prime[i] - 1 <= F && prime[i] - 1 <= n; ++ i) 
		if(n % (prime[i] - 1) == 0) {         //如果我们枚举的因子可以被整除
			int t = n / (prime[i] - 1);       //枚举该因子的个数
			long long res = sum * prime[i];
			DFS(t, i, res);
			while(t % prime[i] == 0) {
				t /= prime[i], res *= prime[i];
				DFS(t, i, res);
			}
		}
}

int main() {
	n = read(), F = std :: sqrt(n);
	notPrime[0] = notPrime[1] = 1;
	for(int i = 2; i <= 50000; ++ i) {
		if(!notPrime[i]) prime[++ cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= 50000; ++ j) {
			notPrime[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	DFS(n, 0, 1);
	if(ans <= 2147483647) printf("%lld\n", ans);
	else printf("-1\n");
}