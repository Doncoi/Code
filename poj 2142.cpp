#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

int a, b, n; 

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int exGcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	}

	int ans = exGcd(b, a % b, y, x);
	y -= x * (a / b);
	return ans;
}

int main() {
	while(scanf("%d %d %d", &a, &b, &n) && (a + b + n)) {
		int x, y, tmp = gcd(a, b);
		a /= tmp, b /= tmp, n /= tmp;
		exGcd(a, b, x, y);

		tmp = x * n;
		int vx = (tmp % b + b) % b;
		int vy = (n - a * vx) / b < 0 ? -(n - a * vx) / b : (n - a * vx) / b;
		
		y = (y * n % a + a) % a;   
		x = (n - b * y) / a < 0 ? -(n - b * y) / a : (n - b * y) / a;

		if(x + y > vx + vy) {
			x = vx, y = vy;
		}
    	
    	printf("%d %d\n", x, y);  
	} 
}
