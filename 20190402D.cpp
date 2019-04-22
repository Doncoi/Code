#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(scanf("%d",&n)!=EOF){
        int o=2*n;
        int s=o+1;
        int num=0;
        while(1){
            if(o>n){
                o=o*2-s;
            }else{
                o=o*2;
            }
            num++;
            if(o==2*n){
                break;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
