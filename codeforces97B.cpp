
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
struct node {
	int x,y;
	bool operator <(const node b)const
	{
		if(x==b.x) return y<b.y;
		else return x<b.x;
	}
};
node a[10005];
set<node>s;
set<node>::iterator it;
void dfs(int l,int h) {
	if(l==h) return;
	int mid = (l+h)/2;
	for(int i=l;i<=h;i++) {
		node ret;
		ret.x = a[mid].x;
		ret.y = a[i].y;
		s.insert(ret);
	}
	dfs(l,mid);
	dfs(mid+1,h);
}
int main() {
	int n;
	cin>>n;
	s.clear();
	for(int i=0;i<n;i++) {
		cin>>a[i].x>>a[i].y;
		s.insert(a[i]);
	}
	sort(a,a+n);
	dfs(0,n-1);
	int t = s.size();
	cout<<t<<endl;
	for(it = s.begin();it!=s.end();it++) {
		cout<<it->x<<" "<<it->y<<endl;
	}
	return 0;
}
