#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int n,t; 
    scanf("%d%d",&n,&t);
    long long a[200005];
    for(int i=1;i<=n;i++) 
    scanf("%d",&a[i]);
    vector <long long> x;
    while(t--){
        int f=0;
        int l,r; 
        scanf("%d%d",&l,&r);
        if(r-l+1>47) 
        f=1;
        else{
            x.clear();
            for(int i=l;i<=r;i++) 
            x.push_back(a[i]);
            sort(x.begin(),x.end());
            for(int i=2;i<x.size();i++){
                if(x[i]<x[i-1]+x[i-2]){
                    f=1;
                }
            }
        }
        if(f) 
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}