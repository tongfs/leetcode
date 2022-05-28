/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> map;
        for (auto c: secret) map[c] ++ ;
        int tot = 0;
        for (auto c: guess)
            if (map[c]) {
                map[c] -- ;
                tot ++ ;
            }
        int bulls = 0;
        for (int i = 0; secret[i]; i ++ )
            if (secret[i] == guess[i])
                bulls ++ ;
        return to_string(bulls) + "A" + to_string(tot - bulls) + "B";
    }
};
// @lc code=end

