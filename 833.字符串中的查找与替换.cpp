/*
 * @lc app=leetcode.cn id=833 lang=cpp
 * @lcpr version=21910
 *
 * [833] 字符串中的查找与替换
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return indices[i] < indices[j];
        });

        for (int i = n - 1; i >= 0; i--) {
            int k = idx[i], j = indices[k];
            int len = sources[k].size();
            if (s.substr(j, len) == sources[k])
                s = s.substr(0, j) + targets[k] + s.substr(j + len);
        }

        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n[0,2]\n["a","cd"]\n["eee","ffff"]\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n[0,2]\n["ab","ec"]\n["eee","ffff"]\n
// @lcpr case=end

 */

