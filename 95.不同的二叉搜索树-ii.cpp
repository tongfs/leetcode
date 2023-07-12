/*
 * @lc app=leetcode.cn id=95 lang=cpp
 * @lcpr version=21909
 *
 * [95] 不同的二叉搜索树 II
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, vector<TreeNode*>>> map;

    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return {nullptr};
        if (map[l][r].size()) return map[l][r];

        vector<TreeNode*> res;
        for (int i = l; i <= r; i++) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto l : left) {
                for (auto r : right) {
                    auto root = new TreeNode(i);
                    root->left = l, root->right = r;
                    res.push_back(root);
                }
            }
        }
        return map[l][r] = res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
