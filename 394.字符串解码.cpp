/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=21910
 *
 * [394] 字符串解码
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        int u = 0;
        return dfs(u, s);
    }

    string dfs(int& u, string& s) {
        string res;
        while (u < s.size() && s[u] != ']') {
            if (isdigit(s[u])) {
                int t = 0;
                while (isdigit(s[u])) t = t * 10 + s[u++] - '0';
                u++;
                string str = dfs(u, s);
                while (t--) res += str;
                u++;
            } else {
                res += s[u++];
            }
        }
        return res;        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */

