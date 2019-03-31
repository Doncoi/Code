#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int size=0;

struct data
{
    int l,size,r,w,rnd,val;
} tr[1000005];
int n;
int root;

int _abs(int x)
{
    if (x>0) return x;
    return (0-x);
}

int _min(int a,int b)
{
    if (a<b) return a;
    return b;
}

void update(int &k)
{
    tr[k].size=tr[tr[k].l ].size+tr[tr[k].r ].size+ tr[k].w;
}

void lturn(int &k)
{
    int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;
    tr[t].size=tr[k].size;update(k);k=t;
}

void rturn(int &k)
{
    int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;
    tr[t].size=tr[k].size;update(k);k=t;
}

void insert(int &k,int x)
{
    if (k==0)    
    {
        size++;k=size;
        tr[k].size=tr[k].w=1;
        tr[k].rnd=rand();
        tr[k].val=x;
        return;
    }
    tr[k].size++;
    if (tr[k].val==x)
    {
        tr[k].w++;
    }
    else
    {
        if (x>tr[k].val) 
        {
            insert(tr[k].r,x);
            if (tr[tr[k].r].rnd<tr[k].rnd) lturn(k);
        }
        else 
        {
            insert(tr[k].l,x);
            if (tr[tr[k].l].rnd<tr[k].rnd ) rturn(k);
        }
    }    
}

int ans=0;

void query_pro(int k,int x)
{
    if (k==0) return ;
    if (tr[k].val==x) 
    {
        ans=x;
        return ;
    }
    if (tr[k].val<x)
    {
        ans=tr[k].val;query_pro(tr[k].r,x);
        }    
    else
        query_pro(tr[k].l,x);
}

void query_sub(int k,int x)
{
    if (k==0) return ;
    if (tr[k].val==x) {
        ans=x;
        return;
    }
    if (tr[k].val>x)
    {
        ans=tr[k].val;query_sub(tr[k].l,x);
    }
    else
        query_sub(tr[k].r,x);
}


int main()
{
    scanf("%d",&n);
    int x;
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        if (scanf ("%d", &x) == EOF) x = 0;
        if (i!=1)
        {
            ans=-1000000000;
            query_pro(root,x);
            int flow_pro=_abs(x-ans);
            ans=-1000000000;
            query_sub(root,x);
            int flow_sub=_abs(x-ans);
            sum+=(long long)_min(flow_pro,flow_sub);    
         }
        else sum+=(long long)x;
        insert(root,x);
    }
    
    printf("%d",(int)sum);
    
    return 0;        
} 
