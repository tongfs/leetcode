/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int l = 1, r = 1;
        for (auto p = root->left; p; p = p->left) l ++ ;
        for (auto p = root->right; p; p = p->right) r ++ ;
        if (l == r) return (1 << l) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

