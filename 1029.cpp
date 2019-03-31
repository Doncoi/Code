#include <cstdio>
#include <iostream>
#include <cstring>

int ans;
std :: string pre, back;

int main() {
	std :: cin >> pre >> back;
	for(int i = 1; i < pre.size(); ++ i)
		for(int j = 0; j < back.size() - 1; ++ j)
			if(pre[i] == back[j] && pre[i - 1] == back[j + 1]) 
				++ ans;
	std :: cout << (1 << ans) << std :: endl;
}
