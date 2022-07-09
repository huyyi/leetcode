// spfa求最短路，可用于负权图，最好O(m)最差O(nm)
// 851. spfa求最短路  https://www.acwing.com/problem/content/853/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int v) {
    e[idx] = b;
    w[idx] = v;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size()) {
         int t = q.front();
         q.pop();

         st[t] = false;

         for (int i = h[t]; i != -1; i = ne[i]) {
             int j = e[i];
             if (dist[j] > dist[t] + w[i]) {
                 dist[j] = dist[t] + w[i];
                 if (!st[j]) {
                     q.push(j);
                     st[j] = true;
                 }
             }
         }
    }
    return dist[n];
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;

    while(m --) {
        int a, b, v;
        cin >> a >> b >> v;
        add(a, b, v);
    }

    int res = spfa();

    if (res > 0x3f3f3f3f / 2) puts("impossible");
    cout << res << endl;
}