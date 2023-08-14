/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=21910
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) map[inorder[i]] = i;
        return dfs(preorder, 0, inorder, 0, n);
    }

    TreeNode* dfs(vector<int>& preorder, int p, vector<int>& inorder, int q, int len) {
        if (!len) return nullptr;

        int mid = map[preorder[p]];
        auto root = new TreeNode(preorder[p]);
        root->left = dfs(preorder, p + 1, inorder, q, mid - q);
        root->right = dfs(preorder, p + (mid - q) + 1, inorder, mid + 1, len - (mid - q) - 1);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

