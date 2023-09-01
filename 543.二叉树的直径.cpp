/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=21910
 *
 * [543] 二叉树的直径
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
    int res = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        int l = 0, r = 0;
        if (root->left) l = dfs(root->left) + 1;
        if (root->right) r = dfs(root->right) + 1;
        res = max(res, l + r);
        return max(l, r);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

