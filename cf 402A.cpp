#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 105

int n;
int a[MAXN], b[MAXN];
int sum[3][6], delta[6];

inline int read() {
	char ch = getchar();  int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res * flag;
}

int main() {
	n = read();  memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= n; ++ i) a[i] = read(), sum[0][a[i]] ++, sum[2][a[i]] ++;
	for(int i = 1; i <= n; ++ i) b[i] = read(), sum[1][b[i]] ++, sum[2][b[i]] ++;
	
	for(int i = 1; i <= 5; ++ i) {
		if(sum[2][i] % 2) {
			printf("-1\n");  return 0;
		}	
		delta[i] = std :: abs(sum[1][i] - sum[0][i]), delta[0] += delta[i];
	}
	
	if(delta[0] == 0) printf("0\n");
	else if(delta[0] >= 4 && !(delta[0] % 4)) printf("%d\n", delta[0] / 4);
	else printf("-1\n");
	return 0;
} 
