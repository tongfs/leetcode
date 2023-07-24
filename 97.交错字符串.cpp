/*
 * @lc app=leetcode.cn id=97 lang=cpp
 * @lcpr version=21910
 *
 * [97] 交错字符串
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;

        vector<bool> f(m + 1);
        f[0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i && s1[i - 1] != s3[i + j - 1]) f[j] = false;
                if (j && s2[j - 1] == s3[i + j - 1]) f[j] = f[j] || f[j - 1];
            }
        }

        return f[m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbcbcac"\n
// @lcpr case=end

// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbbaccc"\n
// @lcpr case=end

// @lcpr case=start
// ""\n""\n""\n
// @lcpr case=end

 */

