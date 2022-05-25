/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> res;

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return res;
    }

    void dfs(TreeNode* root, string path) {
        if (!root) return;

        if (!root->left && !root->right) {
            res.push_back(path + to_string(root->val));
            return;
        }

        path += to_string(root->val) + "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }
};
// @lc code=end

