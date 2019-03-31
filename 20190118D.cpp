#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

int n, t;
bool line[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    n = read(), t = read();
 	char chr;
 	
 	for(int i = 1; i <= n; ++ i)
 	{
 		chr = getchar();
 		if(chr == 'G')
 		{
 			line[i] = true;
 		}
 		else 
 		{
 			line[i] = false;
 		}
 	}  

 	for(int i = 1; i <= t; ++ i)
 	{
 		int pre = 1;
 		while(pre < n)
 		{
 			//std :: cout << pre << ": "; 
 			//std :: cout << (line[pre] ? "G" : "B") << " " << (line[pre + 1] ? "G" : "B") << std :: endl;
 			
 			if(! line[pre] && line[pre + 1])
 			{
 				line[pre] = 1, line[pre + 1] = 0;
 				pre += 2; 
 			}
 			else
 			{
 				++ pre;
			}
 		}
 	}

 	for(int i = 1; i <= n; ++ i)
 	{
 		if(line[i]) 
 		{
 			std :: cout << "G";
 		}
 		else
 		{
 			std :: cout << "B";
 		}
 	}
}
