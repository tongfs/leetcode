/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=21910
 *
 * [93] 复原 IP 地址
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return {};
        dfs(0, 0, s, "");
        return res;
    }

    void dfs(int u, int k, string& s, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();
                res.push_back(path);
            }
            return;
        }

        if (k == 4) return;

        for (int i = u, t = 0; i < s.size(); i++) {
            if (i - u && s[u] == '0') break;
            t = t * 10 + s[i] - '0';
            if (t <= 255) dfs(i + 1, k + 1, s, path + to_string(t) + '.');
            else break;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

