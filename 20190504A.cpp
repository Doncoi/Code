#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
std :: string s;
int main()
{
    while(getline(cin,s))
    {      
        //if(s==EOF)
            //break;
        for(int i = 0; i < s.length() - 1; ++ i)
            std :: cout << s[i];
        std :: cout << "!" << std :: endl;
    }
}