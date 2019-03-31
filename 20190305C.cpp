#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100 + 5
#define MAXM 1000 + 5

int n, m;
std :: string str;
int l[MAXN], r[MAXN], type[MAXN];
int ans_l = 0, ans_r= MAXM;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

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
    for(int i = 1; i <= n; ++ i)
    {
        std :: cin >> str;
        if(str == "on") type[i] = 1;
        else if(str == "none") type[i] = 2;
        else if(str == "off") type[i] = 3;
        std :: cin >> l[i] >> r[i];
    }
    for(int i = 2; i < n; ++ i)
    {
        if(i == 1 || i == n) continue;
        if(type[i] == 2)
        {
            ans_l = max(ans_l, l[i]);
            ans_r = min(ans_r, r[i]);
        }
        else if(type[i] == 1)
        {
            ans_l += l[i], ans_r += r[i]; 
        }
        else if(type[i] == 3)
        {
            ans_l = max(0, ans_l - r[i]), ans_r = max(0, ans_r - l[i]);
        }
        else
        {
            std :: cout << "error at " << i << std :: endl;
        }
    }


    if(type[1] == 1)
    {
        std :: cout << max(0, ans_l - r[1]) << " " << max(0, ans_r - l[1]) << std :: endl; 
    }
    else if(type[1] == 2)
    {
        std :: cout << max(ans_l, l[1]) << " " << min(ans_r, r[1]) << std :: endl;
    }
    else
    {
        std :: cout << ans_l + l[1] << " " << ans_r + r[1] << std :: endl;
    }

    if(type[n] == 1)
    {
        std :: cout << ans_l + l[n] << " " << ans_r + r[n] << std :: endl; 
    }
    else if(type[n] == 2)
    {
        std :: cout << max(ans_l, l[n]) << " " << min(ans_r, r[n]) << std :: endl;
    }
    else
    {
        std :: cout << max(0, ans_l - r[n]) << " " << max(0, ans_r - l[n]) << std :: endl;
    }
    
}
