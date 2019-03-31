#include <cstdio>  
#include <algorithm>  
#define MAXN 1000005 
  
int n, m, B[MAXN], L[MAXN], rt[MAXN];  
long long ans, t;  
  
struct node {  
    int key, l, r, num;  
    long long sum;  
} heap[MAXN];  
  
void up(int x) {  
    heap[x].sum = (long long)(heap[heap[x].l].sum + heap[heap[x].r].sum + (long long)heap[x].key);  
    heap[x].num = heap[heap[x].l].num + heap[heap[x].r].num +1;  
}  
  
int merge(int p,int q) {  
    if (!p || !q) {
    	return p ? p : q;  
    }
    if (heap[p].key < heap[q].key) {
    	std :: swap(p,q);  
    }
    heap[p].r = merge(heap[p].r, q);  

    up(p);  
    std :: swap(heap[p].l, heap[p].r);  
    return p;  
}  
  
void del(int &x) {  
    x = merge(heap[x].l, heap[x].r);  
}  
  
void renew(int x) {  
    heap[x].l = heap[x].r = 0;  
}  
  
int main() {  
    scanf("%d%d", &n, &m);  
    for (int i = 1; i <= n; ++ i) {
    	scanf("%d%d%d", &B[i], &heap[i].key, &L[i]);
    	rt[i] = i, heap[i].num = 1, heap[i].sum=(long long)heap[i].key;  
    }
    for (int i = n; i; -- i) {  
        while (heap[rt[i]].sum > (long long)m) {
        	del(rt[i]);  
        }
        if ((t=(long long)((long long)heap[rt[i]].num*(long long)L[i]))>ans) ans=t;  
        if (rt[i] && B[i]) rt[B[i]]=merge(rt[B[i]],rt[i]);  
    }  
    printf("%lld\n",ans);  
    return 0;  
}  
