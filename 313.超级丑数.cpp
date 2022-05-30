/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        typedef pair<int, int> PII;
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        for (auto x: primes) heap.push({x, 0}); // second 记录指针，初始时都指向 0

        vector<int> q(n, 1);
        for (int i = 1; i < n; ) {
            auto t = heap.top(); heap.pop();
            int val = t.first, idx = t.second;
            if (val != q[i - 1]) q[i ++ ] = val;
            heap.push({(long)val / q[idx] * q[idx + 1], idx + 1});
        }

        return q.back();
    }
};
// @lc code=end

