
#include <stdio.h>
using namespace std;
 
#define Num 101
int N,resultEnd = 1;
int graph[Num][Num] = {};
int degree[Num] = {};
 
void findZeroLine()
{
    int i,j;
    for(i=1;i<=N;i++)
        if(degree[i] == 0)
            break;
    
    degree[i] = -1;
    printf("%d ",i);
    
    for(j=1;j<=N;j++)
        if(graph[i][j] == 1)
            degree[j]--;
}
 
int main()
{
    scanf("%d",&N);
    
    for(int i = 1;i <= N;i++)
    {
        int tmp;
        scanf("%d",&tmp);  
        
        while(tmp != 0)
        {
            graph[i][tmp] = 1;
            degree[tmp]++;
            scanf("%d",&tmp);   
        }
    }
    
    for(int i = 1;i <= N;i++)
        findZeroLine();
        
    return 0;
}