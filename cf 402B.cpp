#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 105

int n, k, tmp, len, ans;
int digit[15];

inline int read() {
	char ch = getchar();  int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res * flag;
}

inline void diseve(int x, int k) {
	tmp = 1, len = 1, ans = 0;
	for(int i = 1; i <= k; ++ i) 
		tmp *= 10;

	for(int i = 1; i <= 10; ++ i) {
		if(x < 10) { digit[i] = x; return;}
		digit[i] = x % 10;
		x /= 10;  len ++;
	}
}

int main() {
	n = read(), k = read();
	diseve(n, k); 

	if(n == tmp) ans = 0;
    else if(n < tmp) 
		ans = len - 1;
	else {
		bool flag = false;
		int res = 0, cnt = 0;
		for(int i = 1; i <= len; ++ i) {
			if(digit[i]) res ++;
			else cnt ++;
			if(cnt == k) {
				flag = true;
				break;
			}
		}

		if(flag) ans = res;
		else ans = len - 1;
	}

	printf("%d\n", ans);
}
