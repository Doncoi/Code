#include <iostream>  
#include <cstring>  
#include <cstdlib>  
#include <cstdio>  
#include <climits>  
#include <algorithm>  
using namespace std;  
  
const int N = 505;  
int a[N], b[N], res[N*2];  
char x[N], y[N];  
int len1, len2;  
  
void init() {  
    len1=strlen(x);  
    len2=strlen(y);  
    memset(a,0,sizeof(a));  
    memset(b,0,sizeof(b));  
    memset(res,0,sizeof(res));  
    for(int i=len1-1,j=0; i>=0; i--)  
        a[j++]=x[i]-'0';  
    for(int i=len2-1,j=0; i>=0; i--)  
        b[j++]=y[i]-'0';  
}  
  
int substraction(int *p1,int *p2,int len1,int len2) {  //减的结果放在数组p1中，不够返回-1,正好返回0  
    if(len1<len2)  
        return -1;  
    bool flag=0;  
    if(len1==len2) {  
        for(int i=len1-1; i>=0; i--) {  
            if(p1[i]>p2[i])  
                flag=1;  
            else if(p1[i]<p2[i])  
                if(!flag)  
                    return -1;  
        }  
    }  
  
    for(int i=0; i<len1; i++) {  
        p1[i]-=p2[i];  
        if(p1[i]<0) {  
            p1[i]+=10;  
            p1[i+1]--;  
        }  
    }  
    for(int i=len1-1; i>=0; i--)   
        if(p1[i])  
            return i+1;  
    return 0;  
}  
  
void output() {  
    for(int i=0; i<N; i++) {  
        if(res[i]>=10) {  
            res[i+1]+=res[i]/10;  
            res[i]%=10;  
        }  
    }  
  
    bool flag=0;  
    for(int i=N-1; i>=0; i--) {  
        if(flag)  
            printf("%d",res[i]);  
        else if(res[i]) {  
            printf("%d",res[i]);  
            flag=1;  
        }  
    }  
    if(!flag)  
        printf("0");  
    printf("\n");  
}  
  
void solve() {  
    init();  
    if(len1<len2) {  
        printf("0\n");  
        return;  
    }  
  
    len1=substraction(a,b,len1,len2);  
    if(len1<0) {  
        printf("0\n");  
        return;  
    }  
    else if(len1==0) {  
        printf("1\n");  
        return;  
    }  
  
    res[0]++;//减掉一次了，商+1  
    int k=len1-len2;  
    if(k<0) {  
        output();  
        return;  
    }  
    else if(k>0) {  
        for(int i=len1-1; i>=0; i--)   
            if(i>=k) b[i]=b[i-k];  
            else b[i]=0;  
    }  
  
    len2=len1;  
    for(int j=0; j<=k; j++) {  
        int temp;  
        while((temp=substraction(a,b+j,len1,len2-j))>=0) {  
            len1=temp;  
            res[k-j]++;//每成功减一次，则商的相应位+1  
        }  
    }  
    output();  
}  
  
int main() { 
    scanf("%s%s",x,y);  
    solve();  
    return 0;  
}  