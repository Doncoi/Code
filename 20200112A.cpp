#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

const int INF = 0x3f3f3f3;

int tmp = 0, n = 0;
int maxn = 0, minn = INF;
long long ans = 0;

int main()
{
	char c = getchar();
	while(c != '\n')
	{
		if(c == '<') ++ tmp;
		else if(c == '>') -- tmp;
		maxn = maxn > tmp ? maxn : tmp;
		minn = minn < tmp ? minn : tmp;
		c = getchar();
		ans += tmp, ++ n;
	}

	if(minn < 0) ans += (long long)(n * minn * -1);
	std :: cout << ans << std :: endl;
}
