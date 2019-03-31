#include <cstdio>
#include <algorithm>

int n, m;
int a[10010];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) 
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; i ++) 
    {
    	std :: next_permutation(a, a + n);
    }
    for (int i = 0; i < n; i ++) 
    {
    	printf("%d ", a[i]);
    }
}