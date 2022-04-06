/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[9];

        // 按行检查
        for (int i = 0; i < 9; i ++ ) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j ++ ) {
                if (board[i][j] != '.') {
                    int u = board[i][j] - '1';
                    if (!st[u]) st[u] = true;
                    else return false;
                }
            }
        }

        // 按列检查
        for (int i = 0; i < 9; i ++ ) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j ++ ) {
                if (board[j][i] != '.') {
                    int u = board[j][i] - '1';
                    if (!st[u]) st[u] = true;
                    else return false;
                }
            }
        }

        // 按块检查
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3) {
                memset(st, 0, sizeof st);
                for (int x = 0; x < 3; x ++ )
                    for (int y = 0; y < 3; y ++ )
                        if (board[i + x][j + y] != '.') {
                            int u = board[i + x][j + y] - '1';
                            if (!st[u]) st[u] = true;
                            else return false;
                        }
            }

        return true;
    }
};
// @lc code=end

