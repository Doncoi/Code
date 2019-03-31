#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

inline void Read(int &Num) {
	char c; c = getchar();
	while (c < бо0бо || c > бо9бо) c = getchar();
	Num = c - бо0бо; c = getchar();
	while (c >= бо0бо && c <= бо9бо) {
		Num = Num * 10 + c - бо0бо;
		c = getchar();
	}
}

const int MaxN = 40000 + 5, MaxBlk = 200 + 5;

int n, m, BlkSize, TotBlk;
int A[MaxN], TL[MaxN], T[MaxN], Cnt[MaxN], L[MaxBlk], R[MaxBlk], First[MaxN], Last[MaxN];
int f[MaxBlk][MaxBlk], g[MaxBlk][MaxBlk];

struct ES {
	int Pos, Num, v;
} E[MaxN];

inline bool Cmp_Num(ES e1, ES e2) {
	if (e1.Num == e2.Num) return e1.Pos < e2.Pos;
	return e1.Num < e2.Num;
}
inline bool Cmp_Pos(ES e1, ES e2) {return e1.Pos < e2.Pos;}

int GetNum(int Num, int x, int y) {
	if (x > y || x > E[Last[Num]].Pos || y < E[First[Num]].Pos) return 0;
	int l, r, mid, p1, p2;
	l = First[Num]; r = Last[Num];
	while (l <= r) {
		mid = (l + r) >> 1;
		if (E[mid].Pos >= x) {
			p1 = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	l = First[Num]; r = Last[Num];
	while (l <= r) {
		mid = (l + r) >> 1;
		if (E[mid].Pos <= y) {
			p2 = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	return p2 - p1 + 1;
}

int main() {
	Read(n); Read(m);
	for (int i = 1; i <= n; ++i) {
		Read(E[i].Num);
		E[i].Pos = i;
	}
	sort(E + 1, E + n + 1, Cmp_Num);
	int v_Index = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == 1 || E[i].Num > E[i - 1].Num) ++v_Index;
		E[i].v = v_Index;
		TL[v_Index] = E[i].Num;
	}
	sort(E + 1, E + n + 1, Cmp_Pos);
	for (int i = 1; i <= n; ++i) A[i] = E[i].v;
	sort(E + 1, E + n + 1, Cmp_Num);
	for (int i = 1; i <= n; ++i) {
		if (First[E[i].v] == 0) First[E[i].v] = i;
		Last[E[i].v] = i;
	}
	BlkSize = (int)sqrt((double)n);
	TotBlk = (n - 1) / BlkSize + 1;
	for (int i = 1; i <= TotBlk; ++i) {
		L[i] = (i - 1) * BlkSize + 1;
		R[i] = i * BlkSize;
	}
	R[TotBlk] = n;
	for (int i = 1; i <= TotBlk; ++i) {
		for (int j = 1; j <= n; ++j) Cnt[j] = 0;
		f[i][i - 1] = 0; g[i][i - 1] = 0;
		for (int j = i; j <= TotBlk; ++j) {
			f[i][j] = f[i][j - 1];
			g[i][j] = g[i][j - 1];	
			for (int k = L[j]; k <= R[j]; ++k) {
				++ Cnt[A[k]];
				if (Cnt[A[k]] > f[i][j] || (Cnt[A[k]] == f[i][j] && A[k] < g[i][j])) {
					f[i][j] = Cnt[A[k]]; g[i][j] = A[k];
				}
			}
		}
	}
	memset(Cnt, 0, sizeof(Cnt));
	for (int i = 1; i <= n; ++i) T[i] = -1;
	int l, r, x, y, Ct, Ans, Cu;
	Ans = 0;
	for (int i = 1; i <= m; ++i) {
		Read(l); Read(r);
		l = (l + Ans - 1) % n + 1; r = (r + Ans - 1) % n + 1;
		if (l > r) swap(l, r);
		x = (l - 1) / BlkSize + 1; if (l != L[x]) ++x;                                                                        
		y = (r - 1) / BlkSize + 1; if (r != R[y]) --y;
		if (x > y) {		
			Ct = 0; Ans = 0;
			for (int j = l; j <= r; ++j) {
				++Cnt[A[j]];
				if (Cnt[A[j]] > Ct || (Cnt[A[j]] == Ct && A[j] < Ans)) {
					Ct = Cnt[A[j]]; Ans = A[j];
				}
			}
			for (int j = l; j <= r; ++j) --Cnt[A[j]];
		}
		else {
			Ct = f[x][y]; Ans = g[x][y];
			for (int j = l; j < L[x]; ++j) {
				++Cnt[A[j]];
				if (T[A[j]] == -1) T[A[j]] = GetNum(A[j], L[x], R[y]);
				Cu = Cnt[A[j]] + T[A[j]];
				if (Cu > Ct || (Cu == Ct && A[j] < Ans)) {
					Ct = Cu; Ans = A[j];
				}
			}
			for (int j = r; j > R[y]; --j) {
				++Cnt[A[j]];
				if (T[A[j]] == -1) T[A[j]] = GetNum(A[j], L[x], R[y]);
				Cu = Cnt[A[j]] + T[A[j]];
				if (Cu > Ct || (Cu == Ct && A[j] < Ans)) {
					Ct = Cu; Ans = A[j];
				}
			}
			for (int j = l; j < L[x]; ++j) {--Cnt[A[j]]; T[A[j]] = -1;}
			for (int j = r; j > R[y]; --j) {--Cnt[A[j]]; T[A[j]] = -1;}
		}
		Ans = TL[Ans];
		printf("%d\n", Ans);
	}
	return 0;
}
