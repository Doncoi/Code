#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

long long a, b, ans;

int main()
{
	std :: cin >> a >> b;
	long long lim = b / 2;
	for(long long i = a; i <= lim; i += a)
	{
		if(!(i % a) && !(b % i)) 
		{
			++ ans;
		}
	}
	if(!(b % a)) ++ ans;
	std :: cout << ans << std :: endl;
}
 