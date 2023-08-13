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
        unordered_map<char, int> smap, tmap;
        for (auto c : t) tmap[c]++;

        string res;
        for (int i = 0, j = 0, cnt = 0; j < s.size(); j++) {
            smap[s[j]]++;
            if (smap[s[j]] <= tmap[s[j]]) cnt++;
            while (smap[s[i]] > tmap[s[i]]) smap[s[i++]]--;
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

