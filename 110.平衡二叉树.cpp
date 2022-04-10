/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    typedef pair<bool, int> PII;
    
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

    PII dfs(TreeNode* root) {
        if (!root) return {true, 0};

        auto l = dfs(root->left), r = dfs(root->right);
        if (l.first && r.first && abs(l.second - r.second) <= 1)
            return {true, max(l.second, r.second) + 1};
        return {false, 0};
    }
};
// @lc code=end

