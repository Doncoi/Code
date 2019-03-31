#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 200000
#define MOD 1000000007
#define mid (this->l + this->r >> 1)

struct Function
{
	int k, b;

	Function(int k = 1, int b = 0) : k(k), b(b) {}

	int operator()(int x)
	{
		return ((long long)x * k % MOD + b) % MOD;
	}
} origin[MAXN];

Function merge(const Function &l, const Function &r)
{
	Function result;
	result.k = (long long)l.k * r.k % MOD;
	result.b = ((long long)r.k * l.b % MOD + r.b) % MOD;
	return result;
}

struct SegmentTree
{
	int l, r;
	SegmentTree *lc, *rc;

	Function func;

	SegmentTree(int l, int r) : l(l), r(r), lc(NULL), rc(NULL) {}

	void update()
	{
		func = merge(lc->func, rc->func);
	}

	void build()
	{
		if(r - l == 1)
		{
			func = origin[l];
		}
		else
		{
			lc = new SegmentTree(l, mid), lc->build();
			rc = new SegmentTree(mid, r), rc->build();

			update();
		}
	}

	void modify(int x, const Function &func)
	{ 
		if(r - l == 1)
		{
			this->func = func;
		}
		else
		{
			(x < mid ? lc : rc)->modify(x, func);
			update();
		}
	}

	Function query(int l, int r)
	{
		if(l == this->l && r == this->r) 
		{
			return func;
		}
		else
		{
			Function ans;


			if(l < mid)
			{
				ans = merge(ans, lc->query(l, std :: min(mid, r)));
			}
			if(r > mid)
			{
				ans = merge(ans, rc->query(std :: min(mid, l), r));
			}
			return ans;
		}
	}
};

int n, m;

struct Solver
{
	SegmentTree *S;

	void build()
	{
		S = new SegmentTree(0, n);
		S->build();
	}

	void modify(int x, int k, int b)
	{
		S->modify(x, Function(k, b));
	}

	int query(int l, int r, int x)
	{
		Function f = S->query(l, r + 1);
		return f(x);
	}
} solver;

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int main()
{
	n = read(), m = read();
	for(Function *f = origin; f != origin + n; f ++)
	{
		f->k = read(), f->b = read();
	}

	solver.build();
	for(int i = 0; i < m; ++ i)
	{
		char opt = getchar();
		while(opt != 'M' && opt != 'Q')
		{
			opt = getchar();
		}

		if(opt == 'M')
		{
			int x = read(), k = read(), b = read();
			solver.modify(x - 1, k, b);
		}
		else if(opt == 'Q')
		{
			int l = read(), r = read(), x = read();
			printf("%d\n", solver.query(l, r, x));
		}
		else throw;
	}

	return 0;
} 
