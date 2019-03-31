#include <iostream>

long long a, b;

long long work() {
	long long cnt = 0;
	while(b){  
        long long e = a/b, d = a%b;  
        cnt += e;  
        a = b; b = d;  
    }  

    return cnt;
}

int main() {
	std :: cin >> a >> b;
	std :: cout << work();
}
