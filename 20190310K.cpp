#include <cstdio>
#include <cstring>
#include <iostream>

int main()
{
	long long a, b, c, x;
	std :: cin >> a >> b >> c;
	if(a + b < c)
	{
		x = a + (b * 2) + 1;
	}
	else
	{
		x = b + c;
	}
	std :: cout << x << std :: endl;
}
