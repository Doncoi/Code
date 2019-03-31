#include <cstdio>
#include <stack>
#include <iostream>
#define ALPH_SIZE 26
#define MAXN 10000 + 5

 
struct Node
{
    int line, rank;
} martix[ALPH_SIZE + 5];

int n, ans, flg, len;
char alp;
std :: string str;
std :: stack<Node> s;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

bool judge(char tmp)
{
    if(tmp >= 'A' && tmp <= 'Z')
        return true;
    else 
        return false;
}

int main()
{
    for(int i = 0; i < 26; ++ i)
        martix[i].line = martix[i].rank = 0;
    n = read(); 
    while(n --)
    {
        std :: cin >> alp;
        martix[alp - 'A'].line = read();
        martix[alp - 'A'].rank = read();
    }
    
    while(std :: cin >> str)
    {
        len = str.length();
        ans = 0, flg = 0;
       
        for(int i = 0; i < len; ++ i)
        {
            if(judge(str[i]))
            {
                s.push(martix[str[i] - 'A']);
            }
            else if(str[i] == ')')
            {
                Node right = s.top(); s.pop();
                Node left = s.top(); s.pop();
                if(left.rank!=right.line)
                {
                  flg = 1;  break;
                }
                else 
                {
                    ans += left.line * left.rank * right.rank;
                    Node tmp; tmp.line = left.line, tmp.rank = right.rank;
                    s.push(tmp);
                }
            }
        }
        if(! flg)
            std :: cout << ans << std :: endl;
        else
            std :: cout << "error\n";
    }
    
    return 0;
}
