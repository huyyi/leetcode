//
// Created by NADPH on 2022/3/5.
//

// 切豆腐
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<char> drs;
    char c;
    for (int i = 0; drs.size() < m; ++i) {
        cin >> c;
        if (c != ' ') drs.push_back(c);
    }
    vector<int> x{0, n}, y{0, n}, z{0, n};

    int t;
    for (char c : drs) {
        cin >> t;
        if (c == 'x')
            if (t > x[0] && t < x[1]) t - x[0] > x[1] - t ? x[1] = t : x[0] = t;
        if (c == 'y')
            if (t > y[0] && t < y[1]) t - y[0] > y[1] - t ? y[1] = t : y[0] = t;
        if (c == 'z')
            if (t > z[0] && t < z[1]) t - z[0] > z[1] - t ? z[1] = t : z[0] = t;
        cout << (x[1] - x[0]) * (y[1] - y[0]) * (z[1] - z[0]) << endl;
    }
    return 0;
}

