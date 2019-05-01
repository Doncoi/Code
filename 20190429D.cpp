#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    vector<int> r, g, b;
    int n, m, test = 0, i, t;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break;
        test++;
        r.clear();
        g.clear();
        b.clear();
        for(i = 0; i < n * m; i++)
        {
            cin >> t;
            r.push_back(t);
        }
        for(i = 0; i < n * m; i++)
        {
            cin >> t;
            g.push_back(t);
        }
        for(i = 0; i < n * m; i++)
        {
            cin >> t;
            b.push_back(t);
        }
        cout << "Case " << test << ":" << endl;
        for(i = 0; i < n * m; i++)
        {
            cout << (r[i] + g[i] + b[i]) / 3;
            if((i + 1) % m == 0)
                cout << endl;
            else
                cout << ",";
        }
    }
    //system("pause");
    return 0;
}