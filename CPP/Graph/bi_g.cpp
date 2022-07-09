// 860. 染色法判定二分图
// https://www.acwing.com/problem/content/862/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int c[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool dfs(int v, int color) {
    c[v] = color;
    for (int i = h[v]; i != -1; i = ne[i]) {
        int j = e[i];
        if (c[j] == -1) {
            if (!dfs(j, !color)) return false;
        } else {
            if (c[j] == color) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    int a, b;
    while (m --) {
        cin >> a >> b;
        add(a, b);
    }
    memset(c, -1, sizeof c);

    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        if (color[i] == -1)
            if (!dfs(i, 0))
            {
                flag = false;
                break;
            }
    if (flag) puts("No");
    else puts("Yes");
}