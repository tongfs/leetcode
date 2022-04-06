/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        // 解法一：递归
        /* if (n == 1) return "1";
        string str = countAndSay(n - 1), res;
        for (int i = 0; i < str.size(); i ++ ) {
            int cnt = 1;
            while (i + 1 < str.size() && str[i] == str[i + 1]) {
                cnt ++ ;
                i ++ ;
            }
            res += cnt + '0';
            res += str[i];
        }
        return res; */

        // 解法二：迭代
        string res = "1";
        for (int i = 0; i < n - 1; i ++ ) {
            string t;
            for (int j = 0; j < res.size(); ) {
                int k = j + 1;
                while (k < res.size() && res[j] == res[k]) k ++ ;
                t += to_string(k - j) + res[j];
                j = k;
            }
            res = t;
        }
        return res;
    }
};
// @lc code=end

