#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 100 + 5
#define max(a, b) (a > b ? a : b)   
using namespace std;
//f[i][j]表示从(i, j)点滑下去的最大路径长度
int r, c, ans;
int map[maxn][maxn], f[maxn][maxn];

int dfs(int x, int y)
{      
    if(f[x][y] != 1)  return f[x][y];

    int tmp = 0;
    if(x >= 1 && y >= 1 && x < r && y <= c && map[x][y] > map[x + 1][y]) 
    	tmp = max(tmp, dfs(x + 1, y) + 1);
    if(x >= 1 && y >= 1 && x <= r && y < c && map[x][y] > map[x][y + 1]) 
    	tmp = max(tmp, dfs(x, y + 1) + 1);
    if(x > 1 && y >= 1 && x <= r && y <= c && map[x][y] > map[x - 1][y])    
    	tmp = max(tmp, dfs(x - 1, y) + 1);
    if(x >= 1 && y > 1 && x <= r && y <= c && map[x][y] > map[x][y - 1])    
    	tmp = max(tmp, dfs(x, y - 1) + 1);
  
    return f[x][y] = max(f[x][y], tmp);
}

int main()
{
    cin >> r >> c;
    for(int i = 1; i <= r; ++ i)
    {
        for(int j = 1; j <= c; ++ j)
        {
        	cin >> map[i][j]
            f[i][j] = 1;
        }
    }
    for(int i = 1; i <= r; ++ i)
    {
        for(int j = 1; j <= c; ++ j)
        {
            ans = max(ans, dfs(i,j));   
        }
    }
    cout << ans << endl;             
}