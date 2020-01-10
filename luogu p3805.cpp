#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void findBMstr(string& str)
{
    int *p = new int[str.size() + 1];
    memset(p, 0, sizeof(p));

    int mx = 0, id = 0;
    for(int i = 1; i <=  str.size(); i++)
    {
        if(mx > i)
        {
            p[i] = (p[2*id - i] < (mx - i) ? p[2*id - i] : (mx - i));
        }
        else
        {
            p[i] = 1;
        }

        while(str[i - p[i]] == str[i + p[i]])
            p[i]++;

        if(i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }

    }
    int max = 0, ii;
    for(int i = 1; i < str.size(); i++)
    {
        if(p[i] > max)
        {
            ii = i;
            max = p[i];
        }
    }
    max--;

    cout << max << endl;
    delete  p;
}

int main()
{
    string str, str0;
    cin >> str;

    str0 += "$#";
    for(int i = 0; i < str.size(); i++)
    {
        str0 += str[i];
        str0 += "#";
    }

    findBMstr(str0);
    return 0;
}