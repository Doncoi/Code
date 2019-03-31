#include <cstdio>
#include <stack>

int n,ans = 0,x;
bool flag = 0;
std :: stack <int> a;

int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) {
		scanf("%d",&x);
		while(!a.empty()) {
			int t = a.top(); flag = 0;
		    if(x < t) {
		    	ans += a.size();
		    	a.pop(); 
		    	flag = 1;
			}  
			else break; 
		}
        a.push(x); if(!flag) ans++; 
	}
	printf("%d",ans);
}
