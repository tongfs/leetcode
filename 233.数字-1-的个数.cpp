/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        vector<int> num;
        while (n) {
            num.push_back(n % 10);
            n /= 10;
        }

        n = num.size();

        int res = 0;
        for (int i = n - 1; i >= 0; i -- ) {
            int t = get(num, n - 1, i + 1);
            res += t * pow10(i);

            if (num[i] == 1) res += get(num, i - 1, 0) + 1;
            else if (num[i] > 1) res += pow10(i);
        }

        return res;
    }

    int get(vector<int>& num, int l, int r) {
        int res = 0;
        for (int i = l; i >= r; i -- )
            res = res * 10 + num[i];
        return res;
    }

    int pow10(int x) {
        int res = 1;
        while (x -- ) res *= 10;
        return res;
    }
};
// @lc code=end

