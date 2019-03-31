#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100005

int L, R;
int prime[MAXN];

void getPrime() {
	memset(prime, 0, sizeof(prime));

	for(int i = 2; i <= MAXN; ++ i) {
		if(!prime[i]) {
			prime[++ prime[0]] = i;
		}
		for(int j = 1; j <= prime[0] && prime[j] <= MAXN / i; ++ j) {
			prime[prime[j] * i] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

bool notprime[1000010];
int anotherPrime[1000010];

void getAnotherPrime(int L, int R) {
	memset(notprime, false, sizeof(notprime));
	if(L < 2) {
		L = 2;
	}

	for(int i = 1; i <= prime[0] && (long long) prime[i] * prime[i] <= R; ++ i) {
		int s = L / prime[i] + (L % prime[i] > 0);
		if(s == 1) {
			s = 2;
		}

		for(int j = s; (long long)j * prime[i] <= R; ++ j) {
			if((long long)j * prime[i] >= L) {
				notprime[j * prime[i] - L] = true;
			}
		}
	}

	anotherPrime[0] = 0;
	for(int i = 0; i <= R - L; i ++) {
		if(!notprime[i]) {
			anotherPrime[++ anotherPrime[0]] = i + L;
		}
	}
}

int main() {
	getPrime();
	int L , R;
	while(scanf("%d%d", &L, &R) == 2) {
		getAnotherPrime(L, R);
		if(anotherPrime[0] < 2) {
			printf("There are no adjacent primes.\n");
		} else {
			int x1 = 0, x2 = 100000000, y1 = 0, y2 = 0;

			for(int i = 1; i < anotherPrime[0]; ++ i) {
				if(anotherPrime[i + 1] - anotherPrime[i] < x2 - x1) {
					x1 = anotherPrime[i];
					x2 = anotherPrime[i + 1];
				}

				if(anotherPrime[i + 1] - anotherPrime[i] > y2 - y1){
					y1 = anotherPrime[i];
					y2 = anotherPrime[i + 1];
				}
			}

			printf("%d,%d are closest, %d,%d are most distant.\n", x1, x2, y1, y2);
		}
	}
}
