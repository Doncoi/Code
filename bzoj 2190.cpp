#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 40005

int n, ans;
int phi[MAXN], check[MAXN], prime[MAXN];

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch = '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void getPhi() {
	phi[1] = 1; int cnt = 0;
	for(int i = 2; i <= n; ++ i) {
		if(!check[i]) {prime[++ cnt] = i; phi[i] = i - 1;}
		for(int j = 1; j <= cnt && prime[j] * i <= n; ++ j) {
			check[prime[j] * i] = 1;
			if(i % prime[j]) phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			else {phi[i * prime[j]] = phi[i] * prime[j]; break;}
		}
	}
}

int main() {
	n = read(); getPhi();
	for(int i = 1; i < n; ++ i) ans += phi[i];
	printf("%d\n", ans * 2 + 1);
}
