#include <cstdio>
#include <cstring>

long long n, k, ans;

int main() {
	scanf("%d%d", &n, &k);
	long long i = k / n, l = k / (i + 1) + 1, r = n;    ans = 0;

	while(l > 0) {
		ans += (k * (r - l + 1)) - (i * (l + r) * (r - l + 1) / 2);  //n > k时，ans直接加上(n - k) * k
		if(l == 1) break;
		i = k / (l - 1), l = k / (i + 1) + 1, r = k / i;  //将区间缩小至有余数出现处
	}	

	printf("%lld\n", ans);	
}
