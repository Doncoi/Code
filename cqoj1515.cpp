#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n, m, a[100];
    int i, j, s;
    scanf("%d", &n);

    while(n --)
    {
        s = 0;
        scanf("%d", &m);
        for(i = 0; i < m; i ++)
           scanf("%d", &a[i]);

        if(m == 1)
            printf("%d\n",a[0]);
        //每个数可以和另一个数配对，也可以不配对
        //有偶数个整数
        else if(m % 2 == 0)
        {
            sort(a, a + i);
            for(j = i - 1; j >= 0; j -= 2)
                //有任一个数为0时，不配对收益更高 
                if(a[j] == 0 || a[j - 1] == 0)
                    s += a[j] + a[j - 1];
                //同理
                else if(a[j] == 1 || a[j - 1] == 1)
                    s += a[j] + a[j - 1];
                //配对收益更高
                else
                    s += a[j] * a[j - 1];
            printf("%d\n",s);
        }
        //有奇数个整数
        else if(m % 2 == 1)
        {
            sort(a, a + i);
            for(j = i - 1; j >= 1; j -= 2)
                if(a[j] == 0 || a[j - 1] == 0)
                    s += a[j] + a[j - 1];
                else if(a[j] == 1 || a[j - 1] == 1)
                    s += a[j] + a[j - 1];
                else
                    s += a[j] * a[j - 1];
                s += a[0];
            printf("%d\n",s);
        }
    }
}