#include <iostream>
#include <algorithm> 
#include <string>
#include <cmath>

int a,b;

int main() {
	std :: string sa,sb;
    std :: cin >> sa >> sb;
    if(sa == "monday") a = 1;else if(sa == "tuesday") a =2;else if(sa == "wednesday") a = 3;else if(sa == "thursday") a = 4;else if(sa == "friday") a =5;else if(sa == "saturday") a = 6;else a = 7;
    if(sb == "monday") b = 1;else if(sb == "tuesday") b =2;else if(sb == "wednesday") b = 3;else if(sb == "thursday") b = 4;else if(sb == "friday") b =5;else if(sb == "saturday") b = 6;else b = 7;
    if(a == 1) {
    	if(b == 1 || b == 3 || b == 4) std :: cout << "YES";
		else std :: cout << "NO"; 
	}
	else if(a == 2) {
    	if(b == 2 || b == 4 || b == 5) std :: cout << "YES";
		else std :: cout << "NO"; 
	}
	else if(a == 3) {
    	if(b == 3 || b == 5 || b == 6) std :: cout << "YES";
		else std :: cout << "NO"; 
	}
	else if(a == 4) {
    	if(b == 4 || b == 6 || b == 7) std :: cout << "YES";
		else std :: cout << "NO"; 
	}
	else if(a == 5) {
    	if(b == 5 || b == 7 || b == 1) std :: cout << "YES";
		else std :: cout << "NO"; 
	}
	else if(a == 6) {
    	if(b == 6 || b == 1 || b == 2) std :: cout << "YES";
		else std :: cout << "NO"; 
	}
	else if(a == 7) {
    	if(b == 7 || b == 2 || b == 3) std :: cout << "YES";
		else std :: cout << "NO"; 
	}
}
