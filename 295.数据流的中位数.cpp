/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

#include "mylib.h"

// @lc code=start
class MedianFinder {
public:
    priority_queue<int> up;
    priority_queue<int, vector<int>, greater<int>> down;

    MedianFinder() {}

    void addNum(int num) {
        if (up.empty() || num <= up.top()) {
            up.push(num);
            if (up.size() > down.size() + 1) {
                down.push(up.top());
                up.pop();
            }
        } else {
            down.push(num);
            if (down.size() > up.size()) {
                up.push(down.top());
                down.pop();
            }
        }
    }
    
    double findMedian() {
        if (up.size() == down.size()) return (up.top() + down.top()) / 2.0;
        else return up.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

