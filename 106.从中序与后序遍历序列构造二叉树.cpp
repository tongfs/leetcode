/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=21909
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) map[inorder[i]] = i;
        return dfs(inorder, 0, postorder, 0, n);    
    }

    TreeNode* dfs(vector<int>& inorder, int i, vector<int>& postorder, int p, int len) {
        if (!len) return nullptr;

        int mid = map[postorder[p + len - 1]];
        auto root = new TreeNode(inorder[mid]);
        root->left = dfs(inorder, i, postorder, p, mid - i);
        root->right = dfs(inorder, mid + 1, postorder, p + mid - i, len - (mid - i) - 1);
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
