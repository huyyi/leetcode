//
// 如何使用比较器对任意类型排序
//
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 1. 在结构体上重载比较运算
// 对点对(x, y)按x的大小排序
void overrideOp() {
    cout << "override operator" << endl;
    struct point {
        int x;
        int y;

        point(): x(0), y(0){}
        point(int _x, int _y): x(_x), y(_y) {}
        // 注意两个const
        bool operator < (const point &p1) const {
            return x < p1.x;
        }
    };
    vector<point> points{};
    for (int i = 0; i < 10; i ++) {
        int x = rand() % 10;
        int y = rand() % 10;
        points.emplace_back(x, y);
        cout << "(" << x << "," << y << ") ";
    }
    cout << endl;
    sort(points.begin(), points.end());
    cout << "Sorted" << endl;
    for (auto p : points) {
        cout << "(" << p.x << ',' << p.y << ") ";
    }
    cout << endl;
}

// 2. 实现比较函数
// 对哈希表的pair对按y排序

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}
void comFunc() {
    cout << "comparator function" << endl;
    vector<pair<int, int>> points{};
    for (int i = 0; i < 10; i ++) {
        int x = rand() % 10;
        int y = rand() % 10;
        points.emplace_back(x, y);
        cout << "(" << x << "," << y << ") ";
    }
    cout << endl;
    cout << "Sorted" << endl;
    sort(points.begin(), points.end(), cmp);
    for (auto p : points) {
        cout << "(" << p.first << ',' << p.second << ") ";
    }
    cout << endl;
}

// 3. 函数对象比较器
class Comper {
public:
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) const {
        return p1.second < p2.second;
    }
};
void funObjComp() {
    cout << "function object comparator" << endl;
    vector<pair<int, int>> points{};
    for (int i = 0; i < 10; i ++) {
        int x = rand() % 10;
        int y = rand() % 10;
        points.emplace_back(x, y);
        cout << "(" << x << "," << y << ") ";
    }
    cout << endl;
    cout << "Sorted" << endl;
    // 注意传入的是对象的实例
    sort(points.begin(), points.end(), Comper());
    for (auto p : points) {
        cout << "(" << p.first << ',' << p.second << ") ";
    }
    cout << endl;
}

int main() {
    overrideOp();
    comFunc();
}