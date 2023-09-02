/*
 * @lc app=leetcode.cn id=662 lang=cpp
 * @lcpr version=21910
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root) q.push({root, 1});

        int res = 0;
        while (q.size()) {
            int len = q.size();
            int l = q.front().second, r;
            while (len--) {
                auto t = q.front();
                q.pop();
                auto p = t.first;
                auto idx = t.second - l + 1;
                r = t.second;
                if (p->left) q.push({p->left, idx * 2LL});
                if (p->right) q.push({p->right, idx * 2LL + 1});
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5,null,null,9,6,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5]\n
// @lcpr case=end

 */

