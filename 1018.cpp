#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

int n,use[25];
string s1,f[25],q;

int asd(string o,string p) {
	int m=0,s=0;
	string e="";
	for(int i=1;i<p.size();i++) {
		m=0;
		for(int j=1;j<=i;j++) {
			if(o[o.size()-1-i+j]==p[j-1])m++;
		}
		if(m==i) {
			s=1;
			break;
		}
	}
	if(s==1)return m;
	return 0;
}

int dfs(string s) {
	if(s.size()>=s1.size())s1=s;
	for(int i=1;i<=n;i++) {
		if(use[i]<2&&asd(s,f[i])!=0) {
			use[i]++;
			string t=s;
			for(int l=1;l<=asd(s,f[i]);l++) {
				t.erase(t.size()-1,1);
			}
			string k=t+f[i];
			dfs(k);
			use[i]--;
		}
	}
	return 0;
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>f[i];
	}
	cin>>q;
	dfs(q);
	cout<<s1.size()<<endl;
	return 0;
}