/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);

        bool t = false;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0; i -- , j -- ) {
            if (j >= 0) a[i] += b[j] - '0';
            a[i] += t;
            t = a[i] >= '2';
            if (t) a[i] -= 2;
        }

        if (t) a = '1' + a;
        return a;
    }
};
// @lc code=end

