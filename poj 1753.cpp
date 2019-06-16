#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 16

bool all_white_or_black(int *bits, int len)
{
    for(int i = 0; i < len - 1; ++ i)
    {
        if(bits[i] != bits[i + 1]) return false;
    }
    return true;
}

void change_color(int *arr, int k)
{
    arr[k] = !(arr[k]);
    int x = k / 4, y = k % 4;
    if(y < 3) arr[k + 1] = !(arr[k + 1]);
    if(y > 0) arr[k - 1] = !(arr[k - 1]);
    if(x > 0) arr[k - 4] = !(arr[k - 4]);
    if(x < 3) arr[k + 4] = !(arr[k + 4]);
}

void combine(int *arr, int len, int *res, int cnt, const int NUM, int *lst)
{
    for(int i = len; i >= cnt; -- i)
    {
        res[cnt - 1] = i - 1;
        if(cnt > 1) 
        {
            combine(arr, i - 1, res, cnt - 1, NUM, lst);
        }
        else
        {
            int *new_arr = (int *)malloc(sizeof(int) *16);
            for(int j = 0; j < 16; ++ j)
            {
                new_arr[j] = arr[j];
            }

            for(int j = NUM - 1; j >= 0; -- j)
            {
                change_color(new_arr, res[j]);
            }
            if(all_white_or_black(new_arr, 16))
            {
                *lst = NUM;
                free(new_arr);
                break;
            }
            free(new_arr);
        }
    }
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') res = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
    return res * flg;
}

int main()
{
    char str[5];
    int bits[16], cnt = 15, line = 4;
    while(line --)
    {
        std :: cin >> str;
        for(int i = 0; i < 4; ++ i)
        {
            if(str[i] == 'b') bits[cnt --] = 1;
            else bits[cnt --] = 0;
        }
    }

    if(all_white_or_black(bits, 16))
    {
        std :: cout << 0 << std :: endl;
    }
    else
    {
        int *new_bits = (int *)malloc(sizeof(int) * 16);
        for(int i = 0; i < 16; ++ i) new_bits[i] = bits[i];

        int lst = 0, j;
        for(j = 1; j <= 16; ++ j)
        {
            int *res = (int *)malloc(sizeof(int) * j);
            combine(new_bits, 16, res, j, j, &lst);
            if(lst == j)
            {
                std :: cout << lst << std :: endl;
                break;
            }

            for(int i = 0; i < 16; ++ i) 
                new_bits[i] = bits[i];

            free(res);
        }
        free(new_bits);

        if(j == 17)
            std :: cout << "Impossible" << std :: endl;
    }
}