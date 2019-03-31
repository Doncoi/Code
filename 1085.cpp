#include<iostream>
#include<climits>
using namespace std;
int n,m;
int f[55][15],g[55][15],a[105],s[105];
int Mod(int t) {
        return (t%10+10)%10;
}
void dp(int p) {
        for (int i=1;i<=n;i++) {
                g[i][1]=f[i][1]=Mod(s[p+i-1]-s[p-1]);
                for (int j=2;j<=m;j++) {
                        f[i][j]=INT_MAX;
                        g[i][j]=0;
                }
        }
        for (int i=2;i<=n;i++)
                for (int j=2;j<=m;j++)
                        for (int k=j-1;k<=i-1;k++) {
                                f[i][j]=min(f[i][j],f[k][j-1]*Mod(s[i+p-1]-s[k+p-1]));
                                g[i][j]=max(g[i][j],g[k][j-1]*Mod(s[i+p-1]-s[k+p-1]));
                        }
}
int main() {
        cin >> n >> m;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=n+1;i<=n*2-1;i++) a[i]=a[i-n];
        for (int i=1;i<=2*n-1;i++) s[i]=s[i-1]+a[i];
        int ans1=INT_MAX,ans2=0;
        for (int i=1;i<=n;i++) {
                dp(i);
                ans1=min(ans1,f[n][m]);
                ans2=max(ans2,g[n][m]);
        }
        cout << ans1 << endl << ans2 << endl;
        return 0;
}
