#include <cstdio>  
#include <iostream>  
  
#define lowbit(i) (i & (-i))  
  
using namespace std;  
  
int readint() {  
    int sign = 1, n = 0; char c = getchar();  
    while(c < '0' || c > '9'){ if(c == '-') sign = -1; c = getchar(); }  
    while(c >= '0' && c <= '9') { n = n*10 + c-'0'; c = getchar(); }  
    return sign*n;  
}  
  
const int Nmax = 200100;  
  
int N, Q;  
  
long long delta[Nmax]; // delta的前缀和   
long long deltai[Nmax]; // delta * i的前缀和   
long long sum[Nmax]; // 原始前缀和  
  
long long Query(long long *array, int pos) {  
    long long temp = 0ll;  
    while(pos > 0)  
    {  
        temp += array[pos];  
        pos -= lowbit(pos);  
    }  
    return temp;  
}  
  
void Update(long long *array, int pos, int x) {  
    while(pos <= N) {  
        array[pos] += x;  
        pos += lowbit(pos);  
    }  
}  
  
int main() {  
    N = readint();  
    for(int i = 1; i <= N; ++i) {  
        int x = readint();  
        sum[i] = sum[i - 1] + x;  
    }  
    Q = readint();  
    while(Q--) { 
        int sign = readint();  
        if(sign == 1) {// 修改：把[l, r]区间均加上x   
          
            int l = readint(), r = readint(), x = readint();  
            Update(delta, l, x);  
            Update(delta, r+1, -x);  
            Update(deltai, l, x * l);  
            Update(deltai, r+1, -x * (r+1));  
        }   
        else {// 查询：[l, r]区间和           
            int l = readint(), r = readint();   
            long long suml = sum[l - 1] + l * Query(delta, l - 1) - Query(deltai, l - 1);  
            long long sumr = sum[r] + (r + 1) * Query(delta, r) - Query(deltai, r);  
            printf("%lld\n", sumr - suml);  
        }  
    }  
      
    return 0;  
}  

