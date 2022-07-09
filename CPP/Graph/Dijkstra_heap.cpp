// 堆优化的D算法，适用于边权非负稀疏图求最短路
// 850. Dijkstra求最短路 II  https://www.acwing.com/problem/content/852/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 150010;

typedef pair<int, int> PII;
int h[N], e[N], ne[N], idx, w[N];
int n, m;
int dist[N];
bool st[N];

void add(int a, int b, int v) {
    w[idx] = v;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});      // first存储距离，second存储节点编号

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);
    int a, b, v;
    while (m--) {
        cin >> a >> b >> v;
        add(a, b, v);
    }

    cout << dijkstra() << endl;
}