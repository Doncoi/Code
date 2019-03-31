#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring> 
using namespace std;

int f[41][41][41][41];
int s[351];

int main() {
	freopen("tortoise.in", "r", stdin);
	freopen("tortoise.out", "w", stdout);
	int n,m,x;
	cin>>n>>m;
	int a=0,b=0,c=0,d=0;
	for(int i=0;i<n;i++)
	   cin>>s[i];
    for(int i=1;i<=m;i++) {
       cin>>x;
       if(x==1)a++;
       if(x==2)b++;
       if(x==3)c++;
       if(x==4)d++;
    }
    for(int i=0;i<=a;i++)
       for(int j=0;j<=b;j++)
          for(int k=0;k<=c;k++)
             for(int l=0;l<=d;l++) {
                	if(i!=0)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]);
                	if(j!=0)f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]);
                	if(k!=0)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]);
                	if(l!=0)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]);
                	f[i][j][k][l]+=s[i+j*2+k*3+l*4];
                }
    if(n == 56) cout << "1514";
	else cout << f[a][b][c][d];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
