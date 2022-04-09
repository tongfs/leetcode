/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> h(n, vector<int>(m));

        for (int i = 0; i < m; i ++ ) if (matrix[0][i] == '1') h[0][i] = 1;
        for (int i = 1; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (matrix[i][j] == '1')
                    h[i][j] = h[i - 1][j] + 1;

        int res = 0;
        for (int i = 0; i < n; i ++ )
            res = max(res, largestRectangleArea(h[i]));
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> h1(n), h2(n);

        for (int i = 0; i < n; i ++ ) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.size()) h1[i] = stk.top();
            else h1[i] = -1;
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n - 1; i >= 0; i -- ) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.size()) h2[i] = stk.top();
            else h2[i] = n;
            stk.push(i);
        }
        
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res = max(res, heights[i] * (h2[i] - h1[i] - 1));
        }
        return res;
    }
};
// @lc code=end

