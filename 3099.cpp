#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int n;
int t[16] = {7,14,17,21,27,  28,35,37,42,47,  49,56,57,63,67,  70};

int main() {
	scanf("%d",&n);
	printf("%d",(n / 70) * 70 + t[n % 16 - 1]);
}
