/*
 * @lc app=leetcode.cn id=979 lang=cpp
 * @lcpr version=21909
 *
 * [979] 在二叉树中分配硬币
 */
#include "mylib.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        int l = dfs(root->left, res), r = dfs(root->right, res);
        res += abs(l) + abs(r);
        return l + r + root->val - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,null,3]\n
// @lcpr case=end

 */

