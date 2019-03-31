#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
const int MAXN = 1000005;

char str[MAXN];
int next[MAXN];

int main() {
	while (scanf("%s", str) != EOF && str[0] != '.') {
		int len = strlen(str);
		int i = 0, j = -1;
		next[0] = -1;
		while (i < len) {
			if (j == -1 || str[i] == str[j]) {
				i++, j++;
				next[i] = j;
			}
			else j = next[j];
		}
		int ans = 1;
		if (len % (len - next[len]) == 0) {
			ans = len / (len - next[len]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
