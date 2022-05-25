/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include "mylib.h"

// @lc code=start
class MyQueue {
public:
    stack<int> stk1, stk2;
    
    MyQueue() {
    }
    
    void push(int x) {
        while (stk2.size()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        stk1.push(x);
    }
    
    int pop() {
        auto t = peek();
        stk2.pop();
        return t;
    }
    
    int peek() {
        while (stk1.size()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
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

