/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<bool>> st;
    vector<vector<char>> matrix;

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        st = vector<vector<bool>>(n, vector<bool>(m));
        matrix = board;

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (dfs(i, j, word, 0))
                    return true;

        return false;
    }

    bool dfs(int x, int y, string& word, int u) {
        if (matrix[x][y] != word[u]) return false;
        if (u == word.size() - 1) return true;

        st[x][y] = true;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b])
                if (dfs(a, b, word, u + 1)) return true;
        }
        st[x][y] = false;

        return false;
    }
};
// @lc code=end

