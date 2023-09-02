/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=21910
 *
 * [232] 用栈实现队列
 */
#include "mylib.h"
// @lc code=start
class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        while (s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }
    
    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }
    
    int peek() {
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1, s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

