#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#define MAXN 25

int n, cnt, ans, len[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++ i) 
		if(len[i] = read()) ++ cnt;
		else ans |= (cnt & 1), cnt = 0;
	
	ans |= (cnt & 1);
	
	if(ans) puts("YES");
	else puts("NO");
}