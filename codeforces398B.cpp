#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define MAXN 100005
#define INF 1000000000005

int start, end, severTime;
int n, a[MAXN], lastServe, ans;

inline int read() {
	char ch = getchar(); int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

int main() {
	start = read(), end = read(), severTime = read(), n = read(); lastServe = end - severTime;
	for(int i = 1; i <= n; ++ i) {
		a[i] = read();  

		if(i == 1) {
			if(a[i] < start) ans = start + severTime;
			else ans = a[i] + severTime;
			continue; 
		} 

		if(ans < a[i] && ans <= lastServe) {
			printf("%d\n", ans);
			return 0;
		} else {
			ans += severTime;
		}
    }

	if(ans > lastServe) 
		printf("%d\n", a[1] - 1);
	else 
		printf("%d\n", ans);
}
