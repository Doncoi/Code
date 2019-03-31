#include <cstdio>
#include <cstring>
#define MAXN 100

int n, k;
int a[MAXN + 5], b[MAXN + 5];
bool used[MAXN + 5] = {false};

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

int main() {
	n = read(), k = read();
	int resn = 0, resk = k;
	for(int i = 1; i <= n; ++ i) {
		int tmp = read();
		if(!(tmp % 10)) ++ resn;
		used[tmp] = true; 
	}
	for(int i = 1; i <= k; ++ i) {
		int tmp = read();
		if(used[tmp]) -- resk;
	}
	
	resn <= resk ? printf("Yes\n") : printf("No\n");
}
