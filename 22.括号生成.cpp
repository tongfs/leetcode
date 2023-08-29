/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=21910
 *
 * [22] 括号生成
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, "");
        return res;
    }

    void dfs(int l, int r, int n, string path) {
        if (r == n) {
            res.push_back(path);
            return;
        }

        if (l < n) dfs(l + 1, r, n, path + '(');
        if (r < l) dfs(l, r + 1, n, path + ')');
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

