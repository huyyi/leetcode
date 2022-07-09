//
// Created by NADPH on 2021/10/8.
//

#include <queue>
#include <vector>
#include <array>
#include <iostream>
#include <cstdlib>

using namespace std;


struct point {
    int x;
    int y;

    point(int _x, int _y): x(_x), y(_y){}

    bool operator< (const point &a) const {
        return y < a.y;
    }
    bool operator> (const point &a) const {
        return y > a.y;
    }
};


void usePQ() {
    // 传入greater，是小顶堆，必须重载operator>
    priority_queue<point, vector<point>, greater<>> minpq;
    // 传入less，是大顶堆，必须重载operator<
    priority_queue<point, vector<point>, less<>> maxpq;
    for (int i = 0; i < 10; i ++) {
        int x = rand() % 10;
        int y = rand() % 10;
        minpq.emplace(x, y);
        maxpq.emplace(x, y);
        cout << "(" << x << "," << y << ") ";
    }
    cout << endl;
    cout << "MinTopHeap" << endl;
    while (!minpq.empty()) {
        auto p = minpq.top();
        minpq.pop();
        cout << "(" << p.x << ',' << p.y << ") ";
    }
    cout << endl;
    cout << "MaxTopHeap" << endl;
    while (!maxpq.empty()) {
        auto p = maxpq.top();
        maxpq.pop();
        cout << "(" << p.x << ',' << p.y << ") ";
    }
}

int main() {
    usePQ();
}