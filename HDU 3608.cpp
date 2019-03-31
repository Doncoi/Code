#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 110005
#define INF 0x7fffffff

char s[MAXN << 1];
int p[MAXN << 1];

int main() {
	while(scanf("%s", s)) {
		int len = std :: strlen(s), id = 0, ans = 0;
		for(int i = len; i >= 0; -- i) 
			s[(i << 1) + 2] = s[i], s[(i << 1) + 1] = '#';

		s[0] = '*';
		for(int i = 2; i < (len << 1) + 1; ++ i) {
			if(p[id] + id > i) 
				p[i] = std :: min(p[(id << 1) - i], p[id] + id - i);
			else 
				p[i] = 1;

			while(s[i - p[i]] == s[i + p[i]]) ++ p[i];
			if(id + p[id] < i + p[i]) id = i;
			if(ans < p[i]) ans = p[i];
		}

		printf("%d", ans - 1);
	}

	 return 0;
}
