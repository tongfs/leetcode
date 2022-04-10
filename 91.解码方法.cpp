/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /*
     * 状态表示：
     *      f[i]: 前i个字符可以解码方法的总数
     * 状态计算：
     *      两种状态：当前数字是一位数字f[i-1]/当前数字是两位数字f[i-2]
     *      f[i] = f[i-1] + f[i-2]（和斐波那契数列类似，但是这两种状态不一定都存在）
     */
    int n;
    vector<int> f;

    int numDecodings(string s) {
        n = s.size();
        s = ' ' + s;
        f = vector<int>(n + 1);

        f[0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            if (s[i] >= '1' && s[i] <= '9') f[i] = f[i - 1];
            if (i >= 2) {
                int t = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (t >= 10 && t <= 26) f[i] += f[i - 2];
            }
        }

        return f[n];
    }
};
// @lc code=end

