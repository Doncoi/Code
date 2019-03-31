#include <iostream>

int n;

int main() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n - i; ++ j) std :: cout << " ";
		std :: cout << "/";
		for(int j = 1; j <= (i - 1) << 1; ++ j) std :: cout << "_";
		std :: cout << "\\";
		for(int j = 1; j <= n - i; ++ j) std :: cout << " ";
		std :: cout << std :: endl;		
	}
}
