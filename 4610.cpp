#include<cstdio>
#include<cstring>
#define FOR(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;
 
const int N = 25;
 
int a[N],c[N];
int n,T,ans;
 
int Qans() {
    memset(c,0,sizeof(c));
    FOR(i,0,13) c[a[i]]++;
    int tot=0;                                    //tot带牌 
    while(c[4]&&c[2]>1)  c[4]--,c[2]-=2,tot++;      
    while(c[4]&&c[1]>1) c[4]--,c[1]-=2,tot++;
    while(c[4]&&c[2]) c[4]--,c[2]--,tot++;
    while(c[3]&&c[2]) c[3]--,c[2]--,tot++;
    while(c[3]&&c[1]) c[3]--,c[1]--,tot++;
    return tot+c[1]+c[2]+c[3]+c[4];                //带牌+三张 对子 单张 
}

void dfs(int now) {
    if(now>=ans) return ;
    int tmp=Qans();
    if(now+tmp<ans)  ans=now+tmp;
    FOR(i,2,13) {                                //三顺子 
        int j=i;
        while(a[j]>=3) j++;
        if(j-i>=2) {
            FOR(j2,i+1,j-1) {
                FOR(k,i,j2) a[k]-=3;
                dfs(now+1);
                FOR(k,i,j2) a[k]+=3;
            }
        }
    }
    FOR(i,2,13) {                                //双顺子 
        int j=i;
        while(a[j]>=2) j++;
        if(j-i>=3) {
            FOR(j2,i+2,j-1) {
                FOR(k,i,j2) a[k]-=2;
                dfs(now+1);
                FOR(k,i,j2) a[k]+=2;
            }
        }
    }
    FOR(i,2,13) {                                //单顺子 
        int j=i;
        while(a[j]>=1) j++;
        if(j-i>=5) {
            FOR(j2,i+4,j-1) {
                FOR(k,i,j2) a[k]--;
                dfs(now+1);
                FOR(k,i,j2) a[k]++;
            }
        }
    }
}

int main() {
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    scanf("%d%d",&T,&n);
    while(T--) {
        memset(a,0,sizeof(a));
        int x,y;
        FOR(i,1,n) {
            scanf("%d%d",&x,&y);
            if(x==1) x=13; else if(x) x--;
            a[x]++;
        }
        ans=1e9;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
