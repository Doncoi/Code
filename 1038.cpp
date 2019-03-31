#include <cstdio>
#include <iostream>
#define p (a * i * i * i + b * i * i + c * i +d)

int main() {
	double a, b, c, d;
	std :: cin >> a >> b >> c >> d;
	for(double i = -100; i <= 100; i += 0.01)
		if(p < 0.0000005 && p > -0.0000005)
	printf("%.2f ",i);	
	return 0;
}