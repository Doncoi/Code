#include <cstdio>
#include <cstring>
#define MAXN 100005
#define SIZE 10

int T, n, tot;
char s[20];

struct Node {
	int trans[SIZE];
	bool isString;

	void clear() {
		memset(trans, 0, sizeof(trans));
		isString = false;
	} 
} trie[MAXN];

bool insert(char *s) {
	int len = strlen(s);
	int u = 1;
	bool flag = false;

	for(int i = 0; i < len; i ++) {
		if(!trie[u].trans[s[i] - '0']) {
			trie[u].trans[s[i] - '0'] = ++ tot;
			trie[tot].clear();
		} else if(i == len - 1) {
			flag = true;
		}

		u = trie[u].trans[s[i] - '0'];
		if(trie[u].isString) {
			flag = true;
		}
	}
	
	trie[u].isString = trie;
	return flag;
} 

int main() {
	scanf("%d", &T);
	while(T --) {
		scanf("%d", &n);
		trie[tot = 1].clear();
		bool ans = false;

		for(int i = 1; i <= n; i ++) {
			scanf("%s", &s);
			if(insert(s)) {
				ans = true;
			}
 		}
 		if(!ans) {
 			printf("YES\n");
 		} else {
 			printf("NO\n");
 		}
	}
}
