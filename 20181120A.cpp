#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 50000 + 5 

int T, n;
int x, y;
int tree[MAXN], sum[MAXN];
char opr[10];

void add(int k, int num) 
{  
    while(k <= n) 
	{  
        tree[k] += num;  
        k += k & -k;            
    }  
}  

int query(int k) 
{               
    int res = 0;  
    while(k) 
	{  
        res += tree[k];  
        k -= k & -k;  
    }  
    return res;
}


int read()
{
	int res = 0, flag = 1; char ch = getchar();
	while(! isdigit(ch)) {if(ch == '-') flag = -1; ch = getchar();}
	while(isdigit(ch)) {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

int main()
{
	T = read();
	for(int t = 1; t <= T; ++ t)
	{
		n = read();
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= n; ++ i)
		{
			sum[i] = read();
			add(i, sum[i]);
		}

		std :: cout << "Case " << t << ":" << std :: endl;
		while(std :: cin >> opr)
		{
			if(opr[0] == 'A')
			{
				std :: cin >> x >> y;
				sum[x] += y;
				add(x, y);
			}
			else if(opr[0] == 'S')
			{
				std :: cin >> x >> y;
				if(sum[x] >= y)
				{
					add(x, (y * -1));
					sum[x] -= y;
				}
				else
				{
					add(x, (sum[x] * -1));
					sum[x] = 0;
				}
			}
			else if(opr[0] == 'Q')
			{
				std :: cin >> x >> y;
				std :: cout << (query(y) - query(x - 1));
			}
			else
			{
				break;
			}
		}
	}	
}
