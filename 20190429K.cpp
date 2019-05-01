#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100 + 5

int T,n;
int t1,t2;
int n1[MAXN], n2[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int main(int argc, char *argv[])
{
    int i,j;
    
    T = read();
    while (T--)
    {
        memset(n1, 0, sizeof(n1));
        memset(n2, 0, sizeof(n2));
        t1 = t2 = 0, n = read();

        for(int i = 0; i < n; ++ i)
        {
            n1[i] = read();
        }
        for(int i = 0; i < n; ++ i)
        {
            n2[i] = read();
            if (n2[i] == n1[i]) t1 ++;
            if (n2[i] == n1[n - 1 - i]) t2 ++;
        }
        
        if (t1 == n && t2 != n)
            std :: cout << "queue" << std :: endl;
        else if (t2 == n && t1 != n)
            std :: cout << "stack" << std :: endl;
        else if (t2 == n && t1 == n)
            std :: cout << "both" << std:: endl;
        else if (t2 != n && t1 != n)
            std :: cout << "neither" << std :: endl;
    }
    return 0;
}
