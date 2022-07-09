// 847. 图中点的层次
// https://www.acwing.com/problem/content/849/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N];
int dist[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int layer() {
    int tt = -1, hh = 0;
    int l = 0;
    int this_l = 1, next_l = 0;

    q[++tt] = 1;

    while (hh <= tt) {
        int t = q[hh ++];
        st[t] = true;
        this_l --;
        for (int i = h[t]; i != -1; i = ne[i]) {
            if (e[i] == n) return l + 1;
            if (!st[e[i]]) {
                q[++tt] = e[i];
                next_l ++;
            }
        }
        if (!this_l) {
            this_l = next_l;
            l ++;
            next_l = 0;
        }
    }
    return -1;
}

int main() {
    memset(h, -1, sizeof h);

    cin >> n >> m;

    int a, b;
    while (m--) {
        cin >> a >> b;
        add(a,b);
    }

    cout << layer() << endl;
}