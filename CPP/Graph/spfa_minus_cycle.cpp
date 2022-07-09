// 852. spfa判断负环  https://www.acwing.com/problem/content/854/
// spfa求最短路，可用于负权图，最好O(m)最差O(nm)
// 851. spfa求最短路  https://www.acwing.com/problem/content/853/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int cnt[N], dist[N];
bool st[N];
int n, m;

void add(int a, int b, int v) {
    e[idx] = b;
    w[idx] = v;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        q.push(i);
        st[i] = true;
    }


    while (q.size()) {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;

    while(m --) {
        int a, b, v;
        cin >> a >> b >> v;
        add(a, b, v);
    }

    if (spfa()) puts("Yes");
    else puts("No");
}