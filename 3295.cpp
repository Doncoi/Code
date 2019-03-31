#include <cstdio>

int n,rom;
long long ans;

int main() {
	scanf("%d",&n);
	ans = 0;
	while(n --) {
        scanf("%d",&rom);
        ans = ans xor rom;
	}
	printf("%lld",ans);
	return 0;
}
