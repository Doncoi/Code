#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

int n, l, a[300];

int judge(int str[], int len) {
	for(int i = 1; i <= len / 2; ++ i)
		if(str[i] != str[len + 1 - i])
			return 0;
	return 1;
}

int plus() {
	int b[300];
	for(int i = 1; i <= l; ++ i) 
		b[i] = a[i];
	for(int i = 1; i <= l; ++ i) {
		a[i] += b[l - i + 1];
		if(a[i] >= n) 
			a[i] %= n, a[i + 1] += 1;
	}
	while(a[l + 1]) ++ l;
}

int main() {
	char m[400];
	std :: cin >> n >> m;
	for(int i = 0; i < strlen(m); ++ i) {
		if(m[i] == 'A') a[i + 1] = 10;
		if(m[i] == 'B') a[i + 1] = 11;
		if(m[i] == 'C') a[i + 1] = 12;
		if(m[i] == 'D') a[i + 1] = 13;
		if(m[i] == 'E') a[i + 1] = 14;
		if(m[i] == 'F') a[i + 1] = 15;
		if(m[i] >= '0' && m[i] <= '9') 
			a[i + 1] = m[i] - '0';
	}

	l = std :: strlen(m);
	for(int i = 1; i <= 30; ++ i) {
		plus();
		if(judge(a, l)) {
			std :: cout << "STEP=" << i;
			return 0;
		}
	}
	std :: cout << "Impossible!";
	return 0;
}
