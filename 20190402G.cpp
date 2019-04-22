
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000 + 5
using namespace std;
int n, d, l, r, cnt;
bool flag[MAXN];
 
int read()
{
    int res = 0, flg = 1;
    char chr = getchar();
    while (!isdigit(chr))
    {
        if (chr == '-')
            flg = -1;
        chr = getchar();
    }
    while (isdigit(chr))
    {
        res = res * 10 + chr - '0';
        chr = getchar();
    }
    return (res * flg);
}
 
int main()
{
    cin>>n>>d;
    for(int i = 1; i <= d; ++ i)
    {
        cin>>l>>r;
        for(int i = l; i <= r; ++ i)
            flag[i] = true;
         
 
        flag[0] = false, l = r = cnt = 0;
        for(int i = 1; i <= n + 1; ++ i)
        {
            if(flag[i]) //has been planted
            {
                if(! flag[0]) 
                {
                    l = i;
                    flag[0] = true;
                }
            }
            else
            {
                if(flag[0])
                {
                    r = i - 1;
                    ++ cnt;
                    if(cnt == 1)
                    {
                        std :: cout << "[" << l << "," << r << "]";
                    }
                    else
                    {
                        std :: cout << ",[" << l << "," << r << "]";
                    }
                    flag[0] = false;
                }
            }
        }
 
        std :: cout << std :: endl;
    }
}