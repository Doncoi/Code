#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10005

int n;
int x, y;
int a[MAXN], b[MAXN], g[MAXN], k[MAXN];
int ans;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++) 
		scanf("%d %d %d %d", &a[i], &b[i], &g[i], &k[i]);
	scanf("%d%d", &x, &y);
	for(int i = n;i >= 1;i --) {
		if((a[i] + g[i] >= x) && (b[i] + k[i] >= y) && a[i] <= x && b[i] <= y) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
}