/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include "mylib.h"

// @lc code=start
class MinStack {
public:
    stack<int> nums, min_stk;

    MinStack() {
    }
    
    void push(int val) {
        nums.push(val);
        if (min_stk.empty()) min_stk.push(val);
        else min_stk.push(min(min_stk.top(), val));
    }
    
    void pop() {
        nums.pop();
        min_stk.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

