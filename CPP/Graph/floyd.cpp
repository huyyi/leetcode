// 854. Floyd求最短路  https://www.acwing.com/problem/content/856/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 210, M = 20010, INF = 1e9;
int d[N][N];
int n, m, k;

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }

    floyd();
    while (k --) {
        int x, y;
        cin >> x >> y;
        if (d[x][y] > INF / 2) puts("impossible");
        else cout << d[x][y] << endl;
    }
    return 0;
}