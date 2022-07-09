// Bellman-Ford 算法求最短边，适用于限制K条边的情况
// 853. 有边数限制的最短路 https://www.acwing.com/problem/content/855/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];
struct Edge {
    int a, b, w;
}edge[M];

int bellman() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i ++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++) {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[n];
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {a, b, w};
    }

    auto res = bellman();
    if (res > 0x3f3f3f3f / 2) puts("impossible");
    else cout << res;
}