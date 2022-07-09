#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <tuple>

using namespace std;
const int N = 1010;
const int M = 10010;
int n, m, k;
typedef pair<int, int> PII;
int x, y, xt, yt;
int f[N][N];
const int dx[]{-2, 2, -2, 2}, dy[]{-2, 2, 2, -2};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

int main() {
    memset(f, 0x3f, sizeof f);
    unordered_map<tuple<int, int>, bool> s;
    queue<PII> q;
    s.clear();
    cin >> n >> m;
    cin >> k;
    int a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        s[{a, b}] = true;
    }
    cin >> x >> y >> xt >> yt;
    f[x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int t = f[x][y];

        for (int i = 0; i < 4; ++i) {
            int xn = x + dx[i];
            int yn = y + dy[i];
            if (xn < 1 || xn > n || yn < 1 || yn > m) continue;

            int xp = x + dx[i] / 2;
            int yp = y + dy[i] / 2;
            if (s.find({xp, yp}) != s.end()) continue;

            f[xn][yn] = min(f[xn][yn], t + 1);
            if (f[xn][yn] == 0x3f3f3f3f)
                q.push({xn, yn});
        }
    }
    int res = f[xt][yt] > 0x3f3f3f3f / 2 ? -1 : f[xt][yt];
    cout << res << endl;
    return 0;
}
