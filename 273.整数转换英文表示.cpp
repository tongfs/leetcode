/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string num0_19[20] = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
    string tens[10] = {
        "", "", "Twenty", "Thirty", "Forty", 
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        };

    string units[4] = {"Billion ", "Million ", "Thousand ", ""};

    string numberToWords(int num) {
        if (!num) return "Zero";
        string res;
        for (int i = 1e9, j = 0; i; num %= i, i /= 1000, j ++ )
            if (num >= i)
                res += get(num / i) + units[j];
        res.pop_back();
        return res;
    }

    string get(int num) {
        string res;
        if (num >= 100) {
            res += num0_19[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            res += tens[num / 10] + ' ';
            num %= 10;
        }
        if (num) res += num0_19[num] + ' ';
        return res;
    }
};
// @lc code=end

