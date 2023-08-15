/*
 * @lc app=leetcode.cn id=113 lang=cpp
 * @lcpr version=21910
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
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode* root, int target) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (root->val == target) res.push_back(path);
            path.pop_back();
            return; 
        }

        if (root->left) dfs(root->left, target - root->val);
        if (root->right) dfs(root->right, target - root->val);
        path.pop_back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */

