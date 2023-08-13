/*
 * @lc app=leetcode.cn id=38 lang=cpp
 * @lcpr version=21910
 *
 * [38] 外观数列
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string str = countAndSay(n - 1), res;
        for (int i = 0; i < str.size(); i++) {
            int cnt = 1;
            while (i + 1 < str.size() && str[i] == str[i + 1]) {
                i++, cnt++;
            }
            res += cnt + '0';
            res += str[i];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

