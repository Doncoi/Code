#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define CAP_A 49
#define CAP_B 33
#define COST_A 3300
#define COST_B 1900

long long n, ans;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
  	std :: cin >> n;
    while(n)
    {
    	if(n <= CAP_B)
    	{
    		n = 0;
    		ans += COST_B;
    	}
    	else if(n > CAP_B && n <= CAP_A)
    	{

    		n = 0;
    		ans += COST_A;
    	}
    	else if(n > CAP_A && n <= (CAP_B * 2))
    	{
    		n = 0;
    		ans += (COST_B + COST_B);
    	}	
    	else if(n > (CAP_B + CAP_B) && n <= (CAP_A + CAP_B))
    	{
    		n = 0;
    		ans += (COST_A + COST_B);
		}
    	else if(n > (CAP_A + CAP_B) && n <= (CAP_B * 3))
    	{
    		n = 0;
    		ans += (COST_B * 3);
    	}
    	else if(n > (CAP_B * 3))
    	{
			//std :: cout << " ALL RIGHT ! " << std :: endl;
    		long long tmp = n / CAP_B - 2;
    		n = n - (long long)(tmp * CAP_B);
    		ans += (long long)(tmp  * COST_B);
    	}
    }

    std :: cout << ans << std :: endl;
}
