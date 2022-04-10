/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> f;
    int numTrees(int n) {
        f = vector<int>(n + 1);
        f[0] = 1;
        return dp(n);
    }

    // 解法一：求卡塔兰数
    int catalan(int n) {
        long long res = 1;
        for (int i = 1, j = n * 2; i <= n; i ++ , j -- ) {
            res *= j;
            res /= i;
        }
        return res / (n + 1);
    }

    // 解法二：记忆化搜索
    int dfs(int n) {
        if (f[n]) return f[n];

        for (int i = 0; i <= n - 1; i ++ ) {
            f[n] += dfs(i) * dfs(n - i - 1);
        }
        return f[n];
    }

    // 解法三：dp
    int dp(int n) {
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= i; j ++ )
                f[i] += f[j - 1] * f[i - j];
        return f[n];
    }
};
// @lc code=end

