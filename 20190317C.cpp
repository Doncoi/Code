#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>

int n;
std :: string s;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

char f(char c)
{
    if(c==')') return '(';
    if(c==']') return '[';
    return 0;
}

bool judge(const std :: string& s)
{
    std :: stack<char> st;
    st.push('0');
    for(int i = 0; i < s.size(); ++ i)
    {
        if(st.top() != f(s[i]))
        st.push(s[i]);
        else st.pop();
    }
    return st.size() == 1;
}

int main()
{
    n = read();
    while(n --)
    {
        getline(std :: cin, s);
        if(s.size() == 0 || judge(s)) 
        	std :: cout << "Yes" << std :: endl;
        else 
        	std :: cout << "No" << std :: endl;
    }
}
