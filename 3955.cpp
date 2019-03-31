#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int b[1000010];
int len = 0;

int twopoint(int l,int r,int x) {
	while(l <= r) {
		int mid = (l + r) / 2;
		if(x == b[mid]) return mid;
		else if(x < b[mid]) r = mid-1;
		else if(x > b[mid]) l = mid+1;
		else if(l > r) return b[mid] > x ? mid : mid + 1;
	}
}

int main() {
	int n;
	cin >> n;
	for(int i = 0;i < n;i ++) {
		int x;
		cin >> x;
		if(len == 0 or x > b[len - 1]) b[len ++] = x;
		else {
			int pos = twopoint(0,len - 1,x);//二分找出第一个大于等于x的东西
			b[pos] = min(b[pos],x);
		}
	}
	cout << len;
}


