#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int getNum(string temp)
{
    if (temp == "zero") return 0;
    if (temp == "one") return 1;
    if (temp == "two") return 2;
    if (temp == "three") return 3;
    if (temp == "four") return 4;
    if (temp == "five") return 5;
    if (temp == "six") return 6;
    if (temp == "seven") return 7;
    if (temp == "eight") return 8;
    if (temp == "nine") return 9;
    if (temp == "ten") return 10;
    if (temp == "eleven") return 11;
    if (temp == "twelve") return 12;
    if (temp == "thirteen") return 13;
    if (temp == "fourteen") return 14;
    if (temp == "fifteen") return 15;
    if (temp == "sixteen") return 16;
    if (temp == "seventeen") return 17;
    if (temp == "eighteen") return 18;
    if (temp == "nineteen") return 19;
    if (temp == "twenty") return 20;
    if (temp == "thirty") return 30;
    if (temp == "forty") return 40;
    if (temp == "fifty") return 50;
    if (temp == "sixty") return 60;
    if (temp == "seventy") return 70;
    if (temp == "eighty") return 80;
    if (temp == "ninety") return 90;
}
int main(){
    int t;
    cin >> t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        string ret;
        int ans = 0,num = 0;
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == ' ')
            {
                if (ret == "million") num *= 1000000, ans += num,num = 0;
                else if (ret == "thousand") num *= 1000,ans += num,num = 0;
                else if (ret == "hundred") num *= 100;
                else if (ret != "and") num += getNum(ret);
                ret = "";
            }
            else ret += s[i];
        }
        //记得最后处理一下 
        if (ret == "million") ans += num * 1000000; 
        else if (ret == "thousand") ans += num * 1000;
        else if (ret == "hundred") ans += num * 100;
        else ans += getNum(ret) + num;
        cout << ans << endl;
    }
    return 0;
}