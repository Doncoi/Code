#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 205

int n, na, nb;
int a[MAXN], b[MAXN];
int ca, cb;

inline int judge(int a, int b) {
	if(a == 0) {
		if(b == 0) return 0;
		else if(b == 1) return 2;
		else if(b == 2) return 1;
		else if(b == 3) return 1;
		else if(b == 4) return 2;
	}
	else if(a == 1) {
		if(b == 0) return 1;
		else if(b == 1) return 0;
		else if(b == 2) return 2;
		else if(b == 3) return 1;
		else if(b == 4) return 2;
	}
	else if(a == 2) {
		if(b == 0) return 2;
		else if(b == 1) return 1;
		else if(b == 2) return 0;
		else if(b == 3) return 2;
		else if(b == 4) return 1;
	}
	else if(a == 3) {
		if(b == 0) return 2;
		else if(b == 1) return 2;
		else if(b == 2) return 1;
		else if(b == 3) return 0;
		else if(b == 4) return 1;
	}
	else if(a == 4) {
		if(b == 0) return 1;
		else if(b == 1) return 1;
		else if(b == 2) return 2;
		else if(b == 3) return 2;
		else if(b == 4) return 0;
	}
}

int main() {
	scanf("%d %d %d", &n, &na, &nb);
	for(int i = 0;i < na;i ++) 
		scanf("%d", &a[i]);
	for(int i = 0;i < nb;i ++) 
		scanf("%d", &b[i]);
	int prea = -1, preb = -1;
	ca = cb = 0;
	while(n --) {
		prea ++;    preb ++;
		int plana = a[prea % na], planb = b[prea % nb];

		int res = judge(plana, planb);
		if(res == 1) ca ++;
		else if(res == 2) cb ++;
	}
	printf("%d %d", ca, cb);
}

