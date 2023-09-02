/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=21910
 *
 * [76] 最小覆盖子串
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        for (auto c : t) t_map[c]++;

        unordered_map<char, int> s_map;
        string res;
        for (int i = 0, j = 0, cnt = 0; j < s.size(); j++) {
            char c = s[j];
            s_map[c]++;
            if (s_map[c] <= t_map[c]) cnt++;
            while (s_map[s[i]] > t_map[s[i]]) s_map[s[i++]]--;
            if (cnt == t.size())
                if (res.empty() || j - i + 1 < res.size())
                    res = s.substr(i, j - i + 1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

