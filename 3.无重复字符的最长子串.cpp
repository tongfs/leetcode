/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), res = 0;
        unordered_map<char, int> h;
        
        for (int i = 0, j = 0; i < n; i ++ )
        {
            char c = s[i];
            h[c] ++ ;
            while (h[c] > 1)
            {
                h[s[j]] -- ;
                j ++ ;
            }

            res = max(res, i - j + 1);
        }

        return res;
    }
};
// @lc code=end

