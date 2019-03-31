#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

long long n, k, cnt;

bool judge() {
	if(n & 1) return false;
	for(int i = 2; i <= std :: sqrt(n); ++ i) 
		if(n % i) return false;
	return true;
} 

int main() {
	scanf("%I64d %I64d", &n, &k);

	if(!judge() && k > 2) {
		printf("-1\n");
		return 0;
	}
 
	for(long long i = 1; i <= (n << 1); ++ i) {
 		if(n % i) continue;
 		if(++ cnt == k) {
 			printf("%I64d\n", i);
 			return 0;
 		}
	}

	printf("-1\n");
	return 0;
}
