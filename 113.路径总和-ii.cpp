/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (root) dfs(root, target);
        return res;
    }

    void dfs(TreeNode* root, int target) {
        target -= root->val;
        path.push_back(root->val);
        if (!target && !root->left && !root->right) res.push_back(path);
        if (root->left) dfs(root->left, target);
        if (root->right) dfs(root->right, target);
        path.pop_back();
    }
};
// @lc code=end

