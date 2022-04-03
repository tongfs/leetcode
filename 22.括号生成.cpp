/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <iostream>
#include <vector>
using namespace std;
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
        if (l > r) dfs(l, r + 1, n, path + ')');
    }
};
// @lc code=end

