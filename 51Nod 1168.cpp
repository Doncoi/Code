#include <cstdio>
#include <cstring>

long long n, k, ans;

int main() {
	scanf("%d%d", &n, &k);
	long long i = k / n, l = k / (i + 1) + 1, r = n;    ans = 0;

	while(l > 0) {
		ans += (k * (r - l + 1)) - (i * (l + r) * (r - l + 1) / 2);  //n > kʱ��ansֱ�Ӽ���(n - k) * k
		if(l == 1) break;
		i = k / (l - 1), l = k / (i + 1) + 1, r = k / i;  //��������С�����������ִ�
	}	

	printf("%lld\n", ans);	
}
