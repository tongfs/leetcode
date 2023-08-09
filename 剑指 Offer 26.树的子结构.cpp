/*
 * @lc app=leetcode.cn id=剑指 Offer 26 lang=cpp
 * @lcpr version=21910
 *
 * [剑指 Offer 26] 树的子结构
 */
#include "mylib.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool dfs(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A || A->val != B->val) return false;
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[3,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,2]\n[4,1]\n
// @lcpr case=end

 */

