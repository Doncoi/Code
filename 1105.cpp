#include <istream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define MIN(x,y) (x<y?x:y)
#define INF 1e7

int dp[100010];
int dd[100010];
int dis[105];

int main(){
  int L,S,T,M;
  int i,j;

  scanf("%d%d%d%d", &L,&S,&T,&M);
  for(i=1; i<=M; ++i)
    scanf("%d", &dis[i]);

  int ans = 0;
  if(S==T){
    for(i=1; i<M; ++i)
      if(dis[i]%S == 0)
        ++ans;
  }
  else{
    dis[0] = 0;
    sort(dis, dis+M+1);
    memset(dd, 0, sizeof(dd));

    for(i=1,j=0; i<=M; ++i){
      if((dis[i] - dis[i-1])>100)
        j += 100;
      else
        j += dis[i]-dis[i-1];
      dd[j] = 1;
    }

    int k = j+100;
    dd[0] = 0;
    for(i=1; i<=k; ++i){
      dp[i] = INF;
      for(j=S; j<=T; ++j){
        if(i<j) break;
        dp[i] = min(dp[i] , dp[i-j]+dd[i]);
      }
    }

    ans = dp[k];
  }
  printf("%d\n", ans);
  return 0;
}