#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN
#define MAXM 
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, cnt;
std :: string s;

inline bool judge(char key) {
	if(key >= 'a' && key <= 'z') {
		printf("key : %c\n", key);
		return true;
	}
	return false;
}

inline bool judge_2(int pos) {
	if(!judge(s[pos])) {
		return false;	
	}
	if((s[pos - 1] != s[pos])) {
		if(judge(s[pos - 1]) && judge(s[pos])) {
			printf("before  ");
			return true;	
		}
		return false;
	}
	if((s[pos + 1] != s[pos])) {
		if(judge(s[pos + 1]) && judge(s[pos])) {
			printf("next ");
			return true;
		}
		return false;
	}
	return false;
}

void init() {
	std :: cin >> n >> s;
}

void solve() {
	if(s[0] != s[1] && judge(s[0]) && judge(s[1])) {
		++ cnt;
	}
	for(int i = 1; i < n; ++ i) {
		if(judge_2(i)) {
			std :: cout << "   " << i << std :: endl;
			++ cnt;
		}
	}

	std :: cout << cnt << std :: endl;
}

int main() {
	init();
	solve();
}
