/*
 * @lc app=leetcode.cn id=823 lang=cpp
 * @lcpr version=21910
 *
 * [823] 带因子的二叉树
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        unordered_map<int, int> map;

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) map[arr[i]] = i;

        vector<int> f(n, 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int t = arr[i] / arr[j];
                    if (map.count(t)) {
                        f[i] = (f[i] + (long long)f[j] * f[map[t]]) % mod;
                    }
                }
            }
            res = (res + f[i]) % mod;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2, 4]\n
// @lcpr case=end

// @lcpr case=start
// [2, 4, 5, 10]\n
// @lcpr case=end

 */

