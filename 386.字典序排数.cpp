/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> res;

    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9 && i <= n; i ++ ) dfs(i, n);
        return res;    
    }

    void dfs(int cur, int n) {
        res.push_back(cur);
        for (int i = 0; i <= 9 && cur * 10 + i <= n; i ++ )
            dfs(cur * 10 + i, n);
    }
};
// @lc code=end

