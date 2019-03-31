#include <bits/stdc++.h>
#define MAXN 200000 + 5

int n, ans;
std :: multiset<int> st;

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
    n = read();
    for(int i = 1; i <= n; ++ i) 
    {
        st.insert(read());
    }

    while(!st.empty())
    {
        int u = *-- st.end();
        st.erase(-- st.end());
        for(int i = 0; i <= 31; ++ i)
        {
            int v = (1 << i) - u;
            if(st.find(v) != st.end()) 
            {
                ++ ans;
                st.erase(st.find(v)); 
                break;
            }
        }
    }

	std :: cout << ans << std :: endl;
}
