#include <cstdio>
#include <cstring>

int n, m;
int f[1000000];

int main() {
	while(scanf("%d%d", &n, &m) == 2) {
		memset(f, -1, sizeof(f));
		printf("%d=", n);

		int pow = 0;
		while(n) {
			f[++ pow] = n % m;
			n = n / m;
			if(f[pow] < 0) 
				f[pow] = f[pow] - m, ++ n;
		}

		for( ; pow >= 1; -- pow) 
			if(f[pow] > 9) {
				char c = 'A' + f[pow] - 10;
				printf("%c", c);
			} else if(f[pow] >= 0) {
				printf("%d", f[pow]);
			}
		printf("(base%d)", m);
	}
}
