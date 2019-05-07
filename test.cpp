#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct str
{
    char a,b;
    str(char i,char j)
    {
        a=i;
        b=j;
    }
    bool t(char i,char j)
    {
        if(a==min(i,j)&&b==max(i,j))
            return true;
        return false;
    }
    bool cf(char i,char j)
    {
        if(a==i||b==i||a==j||b==j)
            return true;
        return false;
    }
};
vector<str>s,f;
bool chazhao(char a,char b)
{
    int n=s.size();
    for(int i=0;i<n;++i)
        if(s[i].t(a,b))
            return true;
    return false;
}
bool cha(int a,int b)
{
    int n=s.size();
    bool ok=true;
    for(int i=0;i<n;++i)
        if(s[i].cf(a,b))
            return false;
    str st(min(a,b),max(a,b));
    s.push_back(st);
    st.a=a,st.b=b;
    f.push_back(st);
    return true;
}
bool cmp(str a,str b)
{
    return a.a<b.a;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l=s1.length();
    
    bool ok=true;
    for(int i=0;i<l;++i)
    {
        char a=s1[i],b=s2[i];
        if(!chazhao(a,b))
        {
            if(!cha(a,b))
            {
                ok=false;
                break;
            }
        }
    }
    if(ok)
    {
        sort(f.begin(),f.end(),cmp);
        for(int i=0;i<f.size();i++)
            cout<<f[i].a<<"->"<<f[i].b<<endl;
    }
    else
        cout<<"Impossible"<<endl;
    return 0;
}
