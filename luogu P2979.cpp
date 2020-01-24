#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000 + 5
#define MAXV 1250 + 5

using namespace std;

int n, T, k, ans;
int f[MAXV], v[MAXN], h[MAXN];

int main() {
    cin >> n >> T >> k;

    for (int i = 1; i <= n; ++ i) {
        cin >> v[i] >> h[i];
        //��ȫ������Ҫ�����������Ҷ���ѹ������
        for (int j = h[i]; j <= T * 5 / 4; j ++)
            f[j] = max(f[j], f[j - h[i]] + v[i]);
    }

    //ö����˵�����
    ans = f[T];
    for (int i = 1; i <= n; ++ i)
        if (h[i] >= k)  //���i��һ�������
            ans = max(ans, f[(T - h[i]) * 5 / 4] + v[i]);
    //��i�������������ˣ���������Ҹ߶�ȫ����С
    //�������ұ�ѹ���󣬼��ϴ����������ΪT
    //��ʱ��ȥ�����ҵ������ʣ�µı�ѹ��������Ӧ��Ϊ
    cout << ans << endl;
}
