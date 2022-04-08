/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        for (int i = 0; i < words.size(); i ++ ) {
            int len = words[i].size();
            int j = i + 1;
            while (j < words.size() && len + 1 + words[j].size() <= maxWidth)
                len += 1 + words[j ++ ].size();

            string line = words[i];
            if (j == words.size() || j == i + 1) {
                for (int k = i + 1; k < j; k ++ ) line += ' ' + words[k];
                line += string(maxWidth - line.size(), ' ');
            } else {
                int cnt = j - i - 1, r = maxWidth - len + cnt;
                int k = 1;
                while (k <= r % cnt) line += string(r / cnt + 1, ' ') + words[i + k], k ++ ;
                while (k <= cnt) line += string(r / cnt, ' ') + words[i + k], k ++ ;
            }

            res.push_back(line);
            i = j - 1;
        }

        return res;
    }
};
// @lc code=end

