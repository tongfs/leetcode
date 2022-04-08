/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> smap, tmap;
        for (auto c : t) tmap[c] ++ ;

        string res;
        for (int i = 0, j = 0, cnt = 0; i < s.size(); i ++ ) {
            smap[s[i]] ++ ;
            if (smap[s[i]] <= tmap[s[i]]) cnt ++ ;

            while (smap[s[j]] > tmap[s[j]]) smap[s[j ++ ]] -- ;
            if (cnt == t.size())
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
        }

        return res;
    }
};
// @lc code=end

