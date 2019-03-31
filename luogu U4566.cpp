#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000005

//using namespace std;

struct Node {
	int x, y;
} a[MAXN];

int n;
int temp[MAXN];  //额外的辅助数组  
long long count;

bool cmp(Node &a, Node &b) {
	return a.x < b.x;
}
  
void Merge(Node *array, int first, int med, int last) {  
    int i = first, j = med + 1;  
    int cur = 0;  
    while (i <= med && j <= last) {   
        if (array[i].y <= array[j].y)  
		    temp[cur++] = array[i ++].y;  
        if (array[i].y > array[j].y) {
            temp[cur++] = array[j ++].y;
            count += (med - i + 1); 
        }        
    }  
    
    while (i <= med) {  
        temp[cur++] = array[i++].y;  
    }  
    
    while (j<= last) {  
        temp[cur++] = array[j++].y;  
    }  
    
    for (int m = 0; m < cur; m ++)  
        array[first++].y = temp[m];   
}  

void MergeSort(Node *array, int first, int last) {  
//	printf("[%d, %d]\n", first, last);
	
    if (first == last) return ;  
    int med = first + ((last - first) >> 1);  
    MergeSort(array, first, med);  
    MergeSort(array, med+1, last);  
    Merge(array, first, med, last);  
}  

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++)
		scanf("%d %d", &a[i].x, &a[i].y);
    count = 0;
    std :: sort(a + 1, a + n + 1, cmp);
    
    MergeSort(a, 1, n);
    printf("%lld", count);
}


