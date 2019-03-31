#include <cmath>
#include <iostream>
#include <algorithm>

int x,y,m,n,L;
int days;

int main() {
	std :: cin >> x >> y >> m >> n >> L;
	int dd = std :: abs(x - y);
	int dv = std:: abs(m - n);
	if((dd % dv) && (dv % dd)) std :: cout << "impossible";
}

