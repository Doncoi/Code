#include <cstring>
#include <cstdio>
#include <vector>
#define M 100010

using namespace std;

vector <int> edge[M];
vector <int> component[M];

int stack[M],top = 0,n,m,instack[M],dfn[M],low[M],componentnumber = 0,index1 = 0,ans,k,p;
int incomponent[M];

void tarjan(int i) {
    int j;
    dfn[i] = low[i] = ++index1;
    instack[i] = true;
    stack[++top] = i;
    for(int e = 0;e < edge[i].size();e ++) {
        j = edge[i][e];
        if(dfn[j] == 0){
            tarjan(j);
            low[i] = min(low[i],low[j]);
        }
        else if(instack[j]) low[i] = min(low[i],dfn[j]);
    }
    if(dfn[i] == low[i]) {
        componentnumber ++;
        do {
            j = tack[top --];
            instack[j] = false;
            component[componentnumber].push_back(j);
            incomponent[j] = componentnumber;
        } while(j != i);
    }
}

int main() {
    scanf("%d%d%d%d",&n,&k,&p,&m);
    for (int i = 1;i <= m;i ++) {
        int x,y;
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
    }
    for (int i = 1;i <= n;i ++)
        if (!dfn[i]) tarjan(i);
            for (int i = 1;i <= componentnumber;i ++) 
    	        if (component[i].size() > k) ans ++;
    if (ans >= p) ans += n;
    printf("%d\n",ans);
    return 0;
}