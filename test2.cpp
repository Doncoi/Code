#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long a, b, c, d;

long long gcd(long long x, long long y)
{
	return (x % y ? gcd(y, x % y) : y);
}


long long quickPow(long long a, long long b)
{
	long long ans = 1;
	for( ; b; a = (a * a), b >>= 1) 
	{
		if(b & 1) ans = (ans * a);
	}
	return ans;
}

int main()
{
	cin >> a >> b >> c >> d;
	long long tmp_1 = quickPow(a, b);
	long long tmp_2 = c + d;
	long long ans = gcd(tmp_1, tmp_2);
	cout << ans << endl;
}