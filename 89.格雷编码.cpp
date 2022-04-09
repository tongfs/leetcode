/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int n;
    vector<bool> st;
    vector<int> res;

    vector<int> grayCode(int n) {
        mirror(n);
        return res;
    }

    // 解法一：通过镜像翻转的方法
    void mirror(int n) {
        res.push_back(0);
        while (n -- ) {
            for (int i = res.size() - 1; i >= 0; i -- ) {
                res[i] <<= 1;
                res.push_back(res[i] + 1);
            }
        }
    }


    // 解法二：暴搜（t表示上一个数，u是已经找到了几个数）
    bool dfs(int t, int u) {
        if (u == (1 << n)) {
            if ((t &= t - 1) == 0) return true;
            else return false;
        }

        for (int j = 0, k; j < n; j ++ ) {
            k = t ^ (1 << j);
            if (!st[k]) {
                res.push_back(k);
                st[k] = true;
                if (dfs(k, u + 1)) return true;
                st[k] = false;
                res.pop_back();
            }
        }

        return false;
    }
};
// @lc code=end

