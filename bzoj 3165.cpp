
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 100100
#define EPS 1e-7
using namespace std;
struct Line{
    double k,b;
    Line() {}
    Line(double _,double __):
        k(_),b(__) {}
    double F(int x)
    {
        return k*x+b;
    }
    friend double Get_Intersection(const Line &l1,const Line &l2)
    {
        return -(l1.b-l2.b)/(l1.k-l2.k);
    }
} lines[M];int tot;

int Max(int x, int y, int pos)
{
    double f1=lines[x].F(pos);
    double f2=lines[y].F(pos);
    if(fabs(f1-f2)>EPS)
        return f1>f2?x:y;
    return min(x,y);
}

struct Segtree{
    Segtree *ls,*rs;
    int line;
    Segtree(Segtree *_,Segtree *__,int ___):
        ls(_),rs(__),line(___) {}
    void Insert(int x,int y,int l,int r,int val)
    {
        int mid=x+y>>1;
        if(x==l&&y==r)
        {
            if( lines[line].F(x)>lines[val].F(x)+EPS && lines[line].F(y)>lines[val].F(y)+EPS )
                return ;
            if( lines[line].F(x)<lines[val].F(x)-EPS && lines[line].F(y)<lines[val].F(y)-EPS )
            {
                line=val;
                return ;
            }
            if( fabs(lines[line].F(x)-lines[val].F(x))<EPS && fabs(lines[line].F(y)-lines[val].F(y))<EPS )
            {
                line=min(line,val);
                return ;
            }
            double temp=Get_Intersection(lines[line],lines[val]);
            if(temp<=mid+0.5)
            {
                if( lines[line].F(x) > lines[val].F(x)-EPS )
                    ls->Insert(x,mid,l,mid,line),line=val;
                else
                    ls->Insert(x,mid,l,mid,val);
            } 
            else
            {
                if( lines[line].F(y) > lines[val].F(y)-EPS )
                    rs->Insert(mid+1,y,mid+1,r,line),line=val;
                else
                    rs->Insert(mid+1,y,mid+1,r,val);
            }
            return ;
        }
        if(r<=mid) ls->Insert(x,mid,l,r,val);
        else if(l>mid) rs->Insert(mid+1,y,l,r,val);
        else ls->Insert(x,mid,l,mid,val) , rs->Insert(mid+1,y,mid+1,r,val);
    }
    int Query(int x,int y,int pos)
    {
        int mid=x+y>>1;
        if(x==y) return line;
        if(pos<=mid) return Max(ls->Query(x,mid,pos),line,pos);
        else return Max(rs->Query(mid+1,y,pos),line,pos);
    }
}*tree;
Segtree* Build_Tree(int x,int y)
{
    int mid=x+y>>1;
    if(x==y) return new Segtree(0x0,0x0,0);
    return new Segtree(Build_Tree(x,mid),Build_Tree(mid+1,y),0);
}

int n,last_ans;

int main()
{
    int i,p,x,x1,y1,x2,y2;
    cin>>n;
    tree=Build_Tree(1,39989);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p);
        if(p==0)
        {
            scanf("%d",&x);
            x=x=((x+last_ans-1)%39989+1);
            printf("%d\n",last_ans=tree->Query(1,39989,x) );
        }
        else
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1=(x1+last_ans-1)%39989+1;
            y1=(y1+last_ans-1)%1000000000+1;
            x2=(x2+last_ans-1)%39989+1;
            y2=(y2+last_ans-1)%1000000000+1;
            if(x1>x2) swap(x1,x2),swap(y1,y2);
            if(x1==x2)
                new(&lines[++tot])Line(0,max(y1,y2));
            else
            {
                double k=(double)(y1-y2)/(x1-x2);
                new(&lines[++tot])Line(k,y1-k*x1);
            }
            tree->Insert(1,39989,x1,x2,tot);
        }
    }
    return 0;
}

