//
// Created by NADPH on 2021/10/4.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> getNextArr(const string &s) {
    if (s.size() == 1) {
        return vector<int>{-1};
    }
    auto res = vector<int>(s.size(), 0);
    res[0] = -1;
    res[1] = 0;

    int cur = 2;
    int m = 0;
    while (cur < s.size()) {
        if (s[cur - 1] == s[m]) {
            res[cur] = m + 1;
            cur++;
            m++;
        } else if (m > 0) {
            m = res[m];
        } else {
            res[cur] = 0;
            cur++;
        }
    }
    return res;
}

int KMP(string s1, string s2) {
    if (s2.empty()) {
        return 0;
    }
    if (s1.empty()  || s1.size() < s2.size()) {
        return -1;
    }
    int p1 = 0;
    int p2 = 0;
    vector<int> next = getNextArr(s2);

    while (p1 < s1.size() && p2 < s2.size()) {
        if (s1[p1] == s2[p2]) {
            p1 ++;
            p2 ++;
        } else if (next[p2] == -1) {
            p1 ++;
        } else {
            p2 = next[p2];
        }
    }
    return p2 == s2.size() ? p1 - p2 : -1;
}

int main() {
    auto res = getNextArr("aabaaf");
}