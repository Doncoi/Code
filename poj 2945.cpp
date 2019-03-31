#include <map>  
#include <queue>  
#include <cmath>  
#include <cstdio>  
#include <cstring>  
#include <stdlib.h>  
#include <iostream>  
#include <algorithm>  
#define maxn 20000+10  
using namespace std;  
struct a{  
    char w[25];  
}s[maxn];  
int ans[maxn];  
bool cmp(a x,a y){  
    return (strcmp(x.w,y.w)<0);  
}  
int main(){  
    int n,m,i,k;  
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m)){  
        memset(ans,0,sizeof(ans));  
        for(int i=0;i<n;++i)scanf("%s",s[i].w);  
        sort(s,s+n,cmp);  
        for(i=0,k=0;i<n;++i){  
            k=0;  
            while(!strcmp(s[i].w,s[i+1].w)){  
                i++;  
                k++;  
            }  
            ans[k]++;  
        }  
        for(i=0;i<n;++i)printf("%d\n",ans[i]);  
    }  
    return 0;  
}  
