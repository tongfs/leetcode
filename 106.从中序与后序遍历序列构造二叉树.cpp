/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i ++ ) map[inorder[i]] = i;
        return dfs(inorder, 0, postorder, 0, n);
    }

    TreeNode* dfs(vector<int>& inorder, int l1, vector<int>& postorder, int l2, int len) {
        if (!len) return nullptr;

        int t = map[postorder[l2 + len - 1]];

        auto res = new TreeNode(inorder[t]);
        res->left = dfs(inorder, l1, postorder, l2, t - l1);
        res->right = dfs(inorder, t + 1, postorder, l2 + t - l1, len - t + l1 - 1);

        return res;
    }
};
// @lc code=end

