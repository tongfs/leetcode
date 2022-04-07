/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        // return method1(num1, num2);
        return method2(num1, num2);
    }

    // 解法一：每一位都用高精度乘法，再结合高精度加法（复杂度高）
    string method1(string num1, string num2) {
        vector<int> A, res;

        for (int i = num1.size() - 1; i >= 0; i -- ) A.push_back(num1[i] - '0');

        for (int i = 0; i < num2.size(); i ++ ) {
            int u = num2[i] - '0';
            reverse(res.begin(), res.end());
            res.push_back(0);
            reverse(res.begin(), res.end());
            auto C = mul(A, u);
            res = add(res, C);
        }

        string ans;
        for (int i = res.size() - 1; i >= 0; i -- ) ans += res[i] + '0';

        return ans;
    }

    // 解法二：每一位先不进位，最后统一处理
    string method2(string num1, string num2) {
        vector<int> A, B;
        int n = num1.size(), m = num2.size();
        for (int i = n - 1; i >= 0; i -- ) A.push_back(num1[i] - '0');
        for (int i = m - 1; i >= 0; i -- ) B.push_back(num2[i] - '0');

        vector<int> C(n + m);
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                C[i + j] += A[i] * B[j];

        for (int i = 0, t = 0; i < n + m; i ++ ) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }
        
        int k = C.size() - 1;
        while (k > 0 && !C[k]) k -- ;

        string res;
        while (k >= 0) res += C[k -- ] + '0';
        
        return res;
    }

    // 高精度乘法
    vector<int> mul(vector<int>& A, int b) {
        vector<int> C;
        int t = 0;

        for (int i = 0; i < A.size() || t; i ++ ) {
            if (i < A.size()) t += A[i] * b;
            C.push_back(t % 10);
            t /= 10;
        }

        return C;
    }

    // 高精度加法
    vector<int> add(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return add(B, A);

        vector<int> C;
        int t = 0;

        for (int i = 0; i < B.size(); i ++ ) {
            if (i < A.size()) t += A[i];
            t += B[i];
            C.push_back(t % 10);
            t /= 10;
        }

        if (t) C.push_back(1);
        while (C.back() == 0 && C.size() > 1) C.pop_back();
        return C;
    }
};
// @lc code=end

