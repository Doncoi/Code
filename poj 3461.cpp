#include <cstdio>
#include <cstring>
#define MAXN 10005
#define MAXM 1000005

int T, n, m, next[MAXN];
char s[MAXN], t[MAXM];

int main() {
	scanf("%d", &T);
	while(T --) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1);
		m = strlen(t + 1);
		for(int i = 2, j = 0; i <= n; ++ i) {
			while(j > 0 && s[j + 1] != s[i]) {
				j = next[j];
			}
			if(s[j + 1] == s[i]) {
				++ j;
			} 
			next[i] = j;
		}

		int ans = 0;
		for(int i = 1, j = 0; i <= m; ++ i) {
			while(j > 0 && s[j + 1] != t[i]) {
				j = next[j];
			}
			if(s[j + 1] == t[i]) {
				++ j;
			}
			if(j == n) {
				ans ++;
				j = next[j];
			}
		}
		printf("%d\n", ans);
	}
}
