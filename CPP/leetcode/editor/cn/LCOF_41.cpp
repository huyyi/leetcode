#include "includes/heads.h"
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> lessHalf;  // 用大顶堆保存左半数据
    priority_queue<int, vector<int>, greater<int>> greaterHalf;  // 用小顶堆保存右半数据
    int n{0};
    MedianFinder() {

    }

    void addNum(int num) {
        n ++;
        if (lessHalf.empty() || num <= lessHalf.top()) lessHalf.push(num);
        else greaterHalf.push(num);

        while(lessHalf.size() - greaterHalf.size() == 2) {
            greaterHalf.push(lessHalf.top());
            lessHalf.pop();
        }
        while(greaterHalf.size() - lessHalf.size() == 2) {
            lessHalf.push(greaterHalf.top());
            greaterHalf.pop();
        }
    }

    double findMedian() {
        if (lessHalf.size() + greaterHalf.size() % 2 == 1) {
            return lessHalf.size() > greaterHalf.size() ? lessHalf.top() : greaterHalf.top();
        }else {
            return (lessHalf.top() + greaterHalf.top()) * 0.5;
        }
    }
};

int main() {
    MedianFinder s;
    s.addNum(-1);
    cout << s.findMedian() << endl;
    s.addNum(-2);
    cout << s.findMedian() << endl;
    s.addNum(-3);
    cout << s.findMedian() << endl;
    s.addNum(-4);
    cout << s.findMedian() << endl;
    s.addNum(-5);
    cout << setprecision(5) << s.findMedian() << endl;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */