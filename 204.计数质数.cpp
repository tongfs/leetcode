/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> st(n);

        for (int i = 2; i <= n - 1; i ++ ) {
            if (!st[i]) primes.push_back(i);
            for (int j = 0; primes[j] <= (n - 1) / i; j ++ ) {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0) break;
            }
        }

        return primes.size();
    }
};
// @lc code=end

