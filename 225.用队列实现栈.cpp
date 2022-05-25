/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include "mylib.h"

// @lc code=start
class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {

    }
    
    void push(int x) {
        if (q1.size()) q1.push(x);
        else q2.push(x);
    }
    
    int pop() {
        if (!q1.size()) swap(q1, q2);
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        auto res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        auto t = pop();
        q2.push(t);
        return t;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

