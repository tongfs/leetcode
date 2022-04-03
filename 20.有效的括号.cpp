/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, int> map = {
            {'(', -1}, {')', 1},
            {'[', -2}, {']', 2},
            {'{', -3}, {'}', 3}
        };
        for (int i = 0; i < s.size(); i ++ ) {
            char c = s[i];
            if (map[c] < 0) stk.push(c);
            else {
                if (stk.size() && map[stk.top()] + map[c] == 0) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

