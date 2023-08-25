/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 * @lcpr version=21910
 *
 * [1448] 统计二叉树中好节点的数目
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
    int res = 0;

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return res;
    }

    void dfs(TreeNode* root, int max_v) {
        if (!root) return;
        if (root->val >= max_v) max_v = root->val, res++;
        dfs(root->left, max_v);
        dfs(root->right, max_v);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,3,null,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,null,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

