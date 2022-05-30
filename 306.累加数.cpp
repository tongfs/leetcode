/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 0; i < num.size(); i++) {
            for (int j = i + 1; j + 1 < num.size(); j++) {
                int a = -1, b = i, c = j;  // a+1 ~ b 是第一个数，b+1 ~ c 是第二个数
                while (true) {
                    // 有前导零
                    if (b - a > 1 && num[a + 1] == '0' || c - b > 1 && num[b + 1] == '0') break;
                    
                    auto x = num.substr(a + 1, b - a), y = num.substr(b + 1, c - b);
                    auto z = add(x, y);
                    if (num.substr(c + 1, z.size()) != z) break;
                    a = b, b = c, c += z.size();
                    if (c + 1 == num.size()) return true;
                }
            }
        }
        return false;
    }

    string add(string a, string b) {
        if (a.size() < b.size()) return add(b, a);

        vector<int> A, B;
        for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

        vector<int> C;
        int t = 0;
        for (int i = 0; i < A.size(); i ++ ) {
            t += A[i];
            if (i < B.size()) t += B[i];
            C.push_back(t % 10);
            t /= 10;
        }
        if (t) C.push_back(1);

        string res;
        for (int i = C.size() - 1; i >= 0; i -- ) res += C[i] + '0';
        return res;
    }
};
// @lc code=end

