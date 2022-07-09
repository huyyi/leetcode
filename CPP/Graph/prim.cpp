// 858. Prim算法求最小生成树  https://www.acwing.com/problem/content/860/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 100010;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int prim() {
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n ; i ++) {
        int t = -1;
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;


        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if (i) res += dist[t];
        st[t] = true;
        for (int k = 1; k <= n; k ++) dist[k] = min(dist[k], g[t][k]);
    }
    return res;
}

int main() {
    memset(g, 0x3f, sizeof  g);
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < n; i ++) {
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int res = prim();
    if (res == 0x3f3f3f3f) puts("impossible");
    else cout << res << endl;
}