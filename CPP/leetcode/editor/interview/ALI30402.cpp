//
// Created by Jinkin Huang on 2022/3/4.
//

// 索引子串
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int t, n;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int res = 0;
        string a;
        for (int i = 1; i <= n; ++i) {
            string idx = to_string(i);
            cin >> a;
            if (a.find(idx) != string::npos) res++;
        }
        cout << res << endl;
    }
}