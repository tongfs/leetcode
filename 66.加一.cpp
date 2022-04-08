/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1, i = n;
        for (; i >= 0; i -- ) {
            if (digits[i] != 9) {
                digits[i] ++ ;
                break;
            }
            digits[i] = 0;
        }
        if (i == -1) {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};
// @lc code=end

