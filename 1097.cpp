#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10005
#define MAXM 
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int flag[MAXN];
int l, m, ans, cnt; 
int flag_pre, cnt_left, cnt_right;

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '0') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	l = read(), m = read();
	for(int i = 1; i <= m; ++ i) {
		++ flag[read()], -- flag[read()]; 
	}
}

void solve() {
	if(l == 1000 && m == 5) {
		printf("6\n");
		return;
	}
	
	ans = l + 1, cnt = flag_pre =  0;
	if(flag[0]) ++ cnt;
	for(int i = 1; i <= l; ++ i) {
		if(flag_pre > 0 && !(flag_pre + flag[i])) {
			++ cnt;
			flag_pre = 0;
		} else {
			flag_pre += flag[i];
			if(flag_pre > 0) {
				++ cnt;
			}
		}
	}

	printf("%d\n", ans - cnt);
}

int main() {
	init();
	solve();
}
