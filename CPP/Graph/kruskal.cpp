// 859. Kruskal算法求最小生成树  https://www.acwing.com/problem/content/861/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010, M = 2e5 + 10;
int n, m;
int p[N];
bool st[M];

struct Edge {
    int a, b, w;

    bool operator< (Edge o) {
        return w < o.w;
    }
} edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    int res = 0, cnt = 0;
    sort(begin(edges), end(edges));
    for (auto edge : edges) {
        int a = edge.a, b = edge.b, c = edge.w;
        int x = find(a), y = find(b);
        if (x == y) continue;
        res += c;
        cnt ++;
        p[x] = y;
        if (cnt == n - 1) return res;
    }
    return 0x3f3f3f3f;
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    int res = kruskal();
    if (res == 0x3f3f3f3f) puts("impossible");
    else cout << res << endl;
}
