#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define MAXN 100005

int n, biggest;
bool is[MAXN];

inline int read() {
	char ch = getchar(); int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

int main() {
	biggest = n = read();
	memset(is, false, sizeof(is));

	for(int i = 1; i <= n; ++ i) {
		is[read()] = true;
		while(biggest && is[biggest]) {
			printf("%d ", biggest);
			is[biggest --] = false;
		}
		printf("\n");
	}
}
