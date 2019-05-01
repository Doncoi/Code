#include<iostream>
#include<map>
using namespace std;
string ma[3]={"QWERTYUIOP","ASDFGHJKL.","ZXCVBNM..."};
map<char,int>x;
map<char,int>y;
int fx[6]={-1,-1,0,0,1,1},fy[6]={0,1,-1,1,-1,0};
bool pan(char a,char b)
{
    int xi=x[a],yi=y[a];
    for(int i=0;i<6;++i)
    {
        int xi=x[a]+fx[i],yi=y[a]+fy[i];
        if(xi>=0&&xi<3&&yi>=0&&yi<10&&ma[xi][yi]==b)
            return true;
    }
    return false;
}
int main()
{
    for(int i=0;i<3;++i)
        for(int j=0;j<10;++j)
            x[ma[i][j]]=i,
            y[ma[i][j]]=j;
    string s1,s2;
    cin>>s1>>s2;
    int l=s1.length();
    bool ok=true;
    for(int i=0;i<l;++i)
        if(s1[i]!=s2[i]&&!pan(s1[i],s2[i]))
        {
            ok=false;
            break;
        }
    if(ok)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
} 