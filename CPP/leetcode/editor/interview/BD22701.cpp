//
// Created by Jinkin Huang on 2022/2/27.
//
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
const int M = 100010;
int n, m, q;
char A[N][N];
char ops[M];
int x, y;

int main() {
    x = 1, y = 1;
    memset(A, '1', sizeof A);
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i] + 1;
    }

    cin >> ops;

    if (A[1][1] == '1') cout << "1 1" << endl;

    for (int i = 0; i < q; ++i) {
        if (ops[i] == 'W') {
            if (A[x - 1][y] != '1') x --;
        } else if (ops[i] == 'A') {
            if (A[x][y - 1] != '1') y --;
        } else if (ops[i] == 'S') {
            if (A[x + 1][y] != '1') x ++;
        } else if (ops[i] == 'D') {
            if (A[x][y + 1] != '1') y ++;
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}