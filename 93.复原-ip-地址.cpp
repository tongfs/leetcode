/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return res;
        dfs(0, 0, s, "");
        return res;
    }

    // u是字符串的第几位，k是第几个数(1~4)
    void dfs(int u, int k, string& s, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();
                res.push_back(path);
            }
            return;
        }

        if (k == 4) return;

        for (int i = u, t = 0; i < s.size(); i ++ ) {
            if (i - u && s[u] == '0') break;
            t = t * 10 + s[i] - '0';
            if (t <= 255) dfs(i + 1, k + 1, s, path + to_string(t) + '.');
            else break;
        }
    }
};
// @lc code=end

