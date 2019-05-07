#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct shu
{
    int id,data,sum;
    shu()
    {
        sum=0;
    }
};
bool cmpid(shu a,shu b)
{
    return a.id<b.id;
};
bool cmpdata(shu a,shu b)
{
    return a.data<b.data;
}
int n;
shu s[100005];
int main()
{
    cin>>n;
    int ans1=0,ans2=0;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&s[i].data);
        s[i].id=i;
        if(s[i].data==1)
            ans1++;
        else if(s[i].data==2)
            ans2++;
    }
    sort(s,s+n,cmpdata);
    int i;
    for(i=0;i<n;++i)
        if(s[i].data!=1)
            break;
    int old=0,oldsum=0;
    for(;i<n;++i)
    {
        if(s[i].data==old)
            s[i].sum=oldsum;
        else if(s[i].data==2)
        {
            int j;
            for(j=i;j<n;++j)
                if(s[j].data>=5)
                    break;
            s[i].sum=ans1+n-j;
            old=s[i].data;oldsum=s[i].sum;
        }
        else if(s[i].data==3)
        {
            int j;
            for(j=i;j<n;++j)
                if(s[j].data>s[i].data)
                    break;
            s[i].sum=ans1+ans2+n-j;
            old=s[i].data;oldsum=s[i].sum;
        }
        else
        {
            int j;
            for(j=i;j<n;++j)
                if(s[j].data>s[i].data)
                    break;
            s[i].sum=ans1+n-j;
            old=s[i].data;oldsum=s[i].sum;
        }
    }
    sort(s,s+n,cmpid);
    for(int i=0;i<n;++i)
        printf("%d ",s[i].sum);
    return 0;
}
