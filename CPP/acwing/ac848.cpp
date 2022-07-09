// 求图的拓扑排序，有重边和自环

#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;
int h[N], e[N], ne[N], idx;
int q[N], hh, tt, in[N];
int n, m;

void add() {
    int a, b;
    cin >> a >> b;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
    in[b] ++;
}

bool top() {
    for (int i = 1; i <= n; i ++)
        if (!in[i]) q[++tt] = i;

    while (hh <= tt) {
        int t = q[hh ++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            in[j] --;
            if (!in[j]) q[++tt] = j;
        }
    }
    return tt == n - 1;
}

int main() {
    hh = 0, tt = -1;
    memset(h, -1, sizeof h);
    cin >> n >> m;

    while (m--) {
        add();
    }

    if (top())
        for (int i = 0; i <= tt; i ++) {
            cout << q[i] << ' ';
        }
    else cout << -1;
}