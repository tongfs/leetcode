/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int cnt = 0;
        for (auto c: seq) {
            if (c == '(') {
                cnt ++ ;
                res.push_back(cnt % 2);
            } else {
                res.push_back(cnt % 2);
                cnt -- ;
            }
        }
        return res;
    }
};
// @lc code=end

