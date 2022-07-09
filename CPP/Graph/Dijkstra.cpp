//
// Created by NADPH on 2021/12/12.
//


#include <iostream>
using namespace std;

const int N = 10010;
int g[N][N], dist[N];
bool st[N];
int n, m;

int dijkstra() {
    dist[1] = 0;

    for (int i = 0; i < n; i ++) {
        int t = -1;

        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;

        st[t] = true;

        for (int j = 1; j <= n; j ++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    return dist[n];
}

int main() {
    cin >> n >> m;

    memset(dist, 0x3f, sizeof dist);
    memset(g, 0x3f, sizeof g);

    int x, y, z;
    while (m--) {
        cin >> x >> y >> z;
        if (x != y) g[x][y] = min(g[x][y], z);
    }

    cout << dijkstra() << endl;
}