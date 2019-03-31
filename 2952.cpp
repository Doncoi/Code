#include <iostream>
int a, q, sum;
int main() {
	std :: cin >> a >> q;
	sum = 1;
	for(int i = 1;i <= a;i ++) {
		sum << 1;
		if(sum == q) {
			printf("0");
			return 0;
		}
		else
			sum = sum > q ? sum - q : sum;
	}
	std :: cout << sum;
}