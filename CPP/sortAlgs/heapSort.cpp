//
// Created by NADPH on 2021/9/22.
//

#include <vector>
#include <iostream>
#include "queue"

using namespace std;


void MaxHeapfy(vector<int>& nums, int i, int heapSize) {
    int left = i * 2 + 1;
    while (i < heapSize) {
        // find the largest index
        int largest = left + 1 < heapSize && nums[left] > nums[left + 1] ? left : left + 1;
        largest = nums[i] > nums[largest] ? i : largest;
        if (largest == i) {
            break;
        }
        swap(nums[i], nums[largest]);
        i = largest;
        left = i * 2 + 1;
    }
}

void ToMaxHeap(vector<int>& nums, int heapSize) {
    for (int i = heapSize >> 1; i >= 0; i--) {
        MaxHeapfy(nums, i, heapSize);
    }
}

void HeapInsert(vector<int>& nums, int num) {
    int i = int(nums.size());
    nums.push_back(num);
    while (i != 0 && nums[i] > nums[i >> 1] ) {
        swap(nums[i], nums[i >> 1]);
        i = i >> 1;
    }
}

void HeapSort(vector<int> &nums, int heapSize) {
    if (heapSize < 2) {
        return;
    }
    while (heapSize != 0) {
        swap(nums[0], nums[heapSize - 1]);
        heapSize --;
        MaxHeapfy(nums, 0, heapSize);
    }
}

int main() {
    auto nums = vector<int>{1, 3, 2, 4, 8};
//    ToMaxHeap(nums, int(nums.size()));
//    HeapInsert(nums, 9);
    // How to use the builtin Priority Queue from STL
    auto PQ = priority_queue<int>{};
    for (auto i : nums) {
        PQ.push(i);
    }
    while (!PQ.empty()) {
        cout << PQ.top() << endl;
        PQ.pop();
    }
}