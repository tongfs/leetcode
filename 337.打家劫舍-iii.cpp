/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        auto t = dfs(root);
        return max(t[0], t[1]);
    }

    vector<int> dfs(TreeNode* root) {
        vector<int> res(2);
        res[1] = root->val;

        if (root->left) {
            auto t = dfs(root->left);
            res[0] += max(t[0], t[1]);
            res[1] += t[0];
        }
        if (root->right) {
            auto t = dfs(root->right);
            res[0] += max(t[0], t[1]);
            res[1] += t[0];
        }

        return res;
    }
};
// @lc code=end

