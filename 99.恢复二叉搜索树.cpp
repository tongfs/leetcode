/*
 * @lc app=leetcode.cn id=99 lang=cpp
 * @lcpr version=21909
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr, *p = nullptr, *q = nullptr;
        stack<TreeNode*> stk;
        if (!root) stk.push(root);

        while (root || stk.size()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            if (stk.size()) {
                root = stk.top();
                stk.pop();
                if (pre && pre->val > root->val) {
                    if (!p) p = pre, q = root;
                    else {
                        q = root;
                        break;
                    }
                }
                pre = root;
                root = root->right;
            }
        }

        swap(p->val, q->val);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,null,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,null,null,2]\n
// @lcpr case=end

 */
