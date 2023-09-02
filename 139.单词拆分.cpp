/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=21910
 *
 * [139] 单词拆分
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (auto& word: wordDict) set.insert(word);
        
        int n = s.size();
        vector<bool> f(n + 1);

        f[0] = true;
        for (int i = 1; i <= n; i++) {
            if (f[i - 1]) {
                for (int j = i; j <= n; j++) {
                    auto str = s.substr(i - 1, j - i + 1);
                    if (set.count(str)) f[j] = true;
                }
            }
        }

        return f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */

