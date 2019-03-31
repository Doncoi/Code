#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 75

//mi数组预处理了每一层的节点数量
long long n, m, k, p, ans, mi[MAXN];

inline int getInt() {
	char ch = getchar(); int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline long long getLong() {
	char ch = getchar(); long long res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline long long calc(long long x, long long y) {
	long long res = (( (x + y) % (p * 2ll) ) * ( (y - x + 1) % (p * 2ll) )) % (p * 2ll);
	res /= 2ll, res %= p;  return res;
}

inline long long work(long long x, long long y, int a, int b) {
	long long res = 0, z; 
	if(a < b) std :: swap(x, y), std :: swap(a, b);
	x ^= (x & (mi[a] - 1)), y ^= (y & (mi[a] - 1)), z = x ^ y;
	if(z > k) 
		res = calc(z - k, z + mi[a] - k);
	else if((z + mi[a]) > k) 
		res = calc(0, z + mi[a] - k - 1);

	res = (res * (mi[b] % p)) % p; 
	return res;
}

int main() {
	int T = getInt(); long long x, y;
	mi[0] = 1ll;
	for(int i = 1; i <= 62; ++ i) mi[i] = mi[i - 1] << 1;

	while(T --) {
		n = getLong(), m = getLong(), k = getLong();
		p = getInt(), x = 0ll, ans = 0ll;
		for(int i = 62; i >= 0; -- i) {
			if(!(n & mi[i])) continue;
			y = 0ll;
			for(int j = 62; j >= 0; -- j) 
				if(m & mi[j]) ans = (ans + work(x, y, i, j)) % p, y |= mi[j];
			x |= mi[i];
		}

		printf("%I64d\n", ans);
	}
}
