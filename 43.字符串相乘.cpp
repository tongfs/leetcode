/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=21910
 *
 * [43] 字符串相乘
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string multiply(string a, string b) {
        int n = a.size(), m = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        vector<int> C(n + m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C[i + j] += (a[i] - '0') * (b[j] - '0');
        
        for (int i = 0, t = 0; i < n + m; i++) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }

        while (C.size() > 1 && C.back() == 0) C.pop_back();
        string res;
        for (int i = C.size() - 1; i >= 0; i--) res += C[i] + '0';
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */

