#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n, m;
int table[1000010];

int main(void)
{
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int l, r;
		cin >> l >> r;
		table[l]++;
		table[r+1]--;
	}
	
	for(int i=1; i<=n; i++)
	{
		table[i] += table[i-1];
	}
	
	bool flag = false;
	int le, ri;
	for(int i=1; i<=n; i++)
	{
		if(flag == false && table[i] == 0)
		{
			le = i;
			flag = true;
		}
		if(flag == true && table[i] == 0)
		{
			ri = i;
		}
		if(flag == true && table[i] != 0)
		{
			cout << le << " " << ri << endl;
			flag = false;
		}
	}
	if(flag == true)
	{
		cout << le << " " << ri << endl;
	}

	return 0;
}
