/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=21910
 *
 * [155] 最小栈
 */
#include "mylib.h"
// @lc code=start
class MinStack {
public:
    MinStack() {}

    void push(int val) {
        s1.push(val);
        if (s2.size()) s2.push(min(s2.top(), val));
        else s2.push(val);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }

private:
    stack<int> s1, s2;
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



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

