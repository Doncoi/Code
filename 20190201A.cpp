#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

int n, k, a;
char s[2];
 
int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
   	while(scanf("%d %d", &n, &k) == 2)
   	{
   		std :: priority_queue<int, std :: vector<int>, std :: greater<int> > q;
   		for(int i = 1; i <= n; ++ i)
   		{
   			scanf("%s", s);
   			if(s[0] == 'I')
   			{
   				scanf("%d", &a);
   				q.push(a);
   				if(q.size() > k)
   				{
   					q.pop();
   				}
   			}
   			else
   			{
   				printf("%d\n", q.top());
   			}
   		}
   	}
}
