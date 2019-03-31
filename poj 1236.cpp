#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <cstring>  
#include <cstdlib>  
#include <string>  
#include <vector>  
#include <cstdio>  
#include <stack>  
#include <cmath>  
#include <queue>  
#include <map>  
#include <set>  
using namespace std;  
#define N 105  
  
vector<int> e[N];  
int dfn[N], low[N],stap[N], stop,belong[N],outdeg[N],indeg[N],dindex, cnt;  
bool instack[N];  
int n, m;  
  
void tarjan(int x){  
    int y = 0;  
    dfn[x]=low[x]=++dindex;  
    instack[x]=true;  
    stap[++stop]=x;  
    for (int i=0; i<e[x].size(); i++) {  
        y=e[x][i];  
        if (!dfn[y]) {  
            tarjan(y);  
            if (low[y]<low[x]) {  
                low[x]=low[y];  
            }  
        }  
        else if (instack[y]&&dfn[y]<low[x]){  
            low[x]=dfn[y];  
        }  
    }  
    if (dfn[x]==low[x]) {  
        cnt++;  
        while (y!=x) {  
            y=stap[stop--];  
            instack[y]=false;  
            belong[y]=cnt;  
        }  
    }  
}  
  
void solve(){  
    stop=dindex=cnt=0;  
    memset(dfn, 0, sizeof(dfn));  
    memset(instack, 0, sizeof(instack));  
    memset(outdeg, 0, sizeof(outdeg));  
    memset(indeg, 0, sizeof(indeg));  
    for (int i=1; i<=n; i++) {  
        if (!dfn[i]) {  
            tarjan(i);  
        }  
    }  
}  
  
int main(){  
    int temp;  
    while (~scanf("%d", &n)) {  
        for (int i=1; i<=n; ++i) {  
            e[i].clear();  
        }  
        for (int i=1; i<=n; i++) {  
            while (scanf("%d",&temp)) {  
                if (temp==0) {  
                    break;  
                }  
                e[i].push_back(temp);  
            }  
        }  
        solve();  
        for (int i=1; i<=n; i++) {  
            int size=e[i].size();  
            for (int j=0; j<size; j++) {  
                if (belong[i]!=belong[e[i][j]]) {  
                    outdeg[belong[i]]++;  
                    indeg[belong[e[i][j]]]++;  
                }  
            }  
        }  
        int sumout=0,sumin=0;  
        for (int i=1; i<=cnt; i++) {  
            if (outdeg[i]==0) {  
                sumout++;  
            }  
            if (indeg[i]==0) {  
                sumin++;  
            }  
        }  
        if (cnt==1) {  
            printf("1\n0\n");  
        }  
        else  
        printf("%d\n%d\n",sumin,max(sumin,sumout));  
          
    }  
    return 0;  
}  
