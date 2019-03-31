#include <iostream>
#include <queue>
using namespace std;
int tm[10000],into[10000][101],sc[101],n,maxt,tot;
int main(){
    priority_queue<int> q;
    cin>>n;
    for(int i=1; i<=n; i++)cin>>tm[i];
    for(int i=1; i<=n; i++)cin>>sc[i];
    for(int i=1; i<=n; i++)maxt=max(maxt,tm[i]),into[tm[i]][++into[tm[i]][0]]=i;
    for(int i=maxt; i>=1; i--){
        for(int j=1; j<=into[i][0]; j++)q.push(sc[into[i][j]]);
        if(q.size()){
            tot+=q.top();
            q.pop();
        }
    }
    cout<<tot<<endl;
    return 0;
}
