/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=21910
 *
 * [17] 电话号码的字母组合
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> map = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        dfs(0, digits, "");
        return res;
    }

    void dfs(int u, string& digits, string path) {
        if (u == digits.size())
            res.push_back(path);
        else
            for (auto c : map[digits[u] - '0'])
                dfs(u + 1, digits, path + c);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

