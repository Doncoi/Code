#include <iostream>
#include <cstdio>
#define MAXN 1000005

int next[MAXN];
char S[MAXN], T[MAXN];
int stlen, tlen;
bool zc[MAXN];
char ans[MAXN];

void getNext() {
	int i, j;
	j = next[0] = -1;
	for(int i = 1; i < tlen; ++ i){
		while(j != -1 && T[i] != T[j + 1]) j = next[j];
		if(T[j + 1] == T[i]) j ++;
		next[i] = j;
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", T);
	tlen = n;
	getNext();

	for(int i = 0; i < n; ++ i) {
		int p = i + 1;
		int bl = p / ( p - 1 - next[p - 1]);
		printf("i: %d p: %d bl: %d next[p]: %d\n ", i, p, bl, next[p]);
		
		if(p % (p - 1 - next[p - 1]) == 0){
			if(bl / k >= bl % k) {
				//putchar('1');
			} else {
				//putchar('0');
			}
		} else {
			if(bl/k>bl%k) {
				//putchar('1');
			} else {
				//putchar('0');
			}
		}
	}
	puts("");
}
