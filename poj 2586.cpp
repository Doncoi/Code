#include<iostream>
using namespace std;
 
int main()
{
    long long s, d, tsum, sum;
    while(scanf("%lld %lld", &s, &d) != EOF)
    {
        int i;
        for(i=1;i<=5;++i)
        {
            tsum=(5 - i) * s - i * d;
            if(tsum < 0) break;
        }
        switch(i)
        {
            case 1: sum = 10 * s - 2 * d; break;
            case 2: sum = 8 * s - 4 * d; break;
            case 3: sum = 6 * s - 6 * d; break;
            case 4: sum = 3 * s - 9 * d; break;
            case 5: sum = -1; break;
        }
        if(sum >= 0) cout << sum << endl;
        else cout << "Deficit" << endl;
    }
    return 0;
}