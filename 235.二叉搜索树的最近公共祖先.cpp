/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

#include "mylib.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) swap(p, q);
        if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};
// @lc code=end

