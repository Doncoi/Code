#include <string>
#include <cstring>
#include <iostream>

std :: string s;
bool judge[30];

int main () {
	judge[0] = true; int pre = 0; std :: cin >> s;

	while(pre < s.length()){
		if (judge[s[pre] - 97]) judge[s[pre ++] - 96] = true;
		else { std :: cout << "NO" << std :: endl; return 0; }
	}

	std :: cout << "YES" << std :: endl;
}
