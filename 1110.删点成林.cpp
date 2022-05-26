/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    unordered_set<int> set;
    vector<TreeNode*> res;

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto x: to_delete) set.insert(x);
        dfs(root, false);
        return res;
    }

    void dfs(TreeNode* &root, bool has_father) {
        if (set.count(root->val)) {
            if (root->left) dfs(root->left, false);
            if (root->right) dfs(root->right, false);
            root = nullptr;
        } else {
            if (!has_father) res.push_back(root);
            if (root->left) dfs(root->left, true);
            if (root->right) dfs(root->right, true);
        }
    }
};
// @lc code=end

