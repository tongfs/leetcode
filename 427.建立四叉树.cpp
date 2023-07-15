/*
 * @lc app=leetcode.cn id=427 lang=cpp
 * @lcpr version=21909
 *
 * [427] 建立四叉树
 */
#include "mylib.h"
// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size() - 1, grid.size() - 1);
    }

    Node* dfs(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        if (x1 > x2) return nullptr;

        if (check(grid, x1, y1, x2, y2))
            return new Node(grid[x1][y1], true);
        

        auto tl = dfs(grid, x1, y1, x1 + x2 >> 1, y1 + y2 >> 1);
        auto tr = dfs(grid, x1, (y1 + y2 >> 1) + 1, x1 + x2 >> 1, y2);
        auto bl = dfs(grid,( x1 + x2 >> 1) + 1, y1, x2, y1 + y2 >> 1);
        auto br = dfs(grid, (x1 + x2 >> 1) + 1, (y1 + y2 >> 1) + 1, x2, y2);
        return new Node(1, 0, tl, tr, bl, br);
    }

    bool check(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                if (grid[i][j] != grid[x1][y1])
                    return false;
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]\n
// @lcpr case=end

 */

