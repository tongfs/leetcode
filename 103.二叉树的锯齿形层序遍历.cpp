/*
 * @lc app=leetcode.cn id=103 lang=cpp
 * @lcpr version=21910
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        bool flag = false;
        vector<vector<int>> res;

        while (q.size()) {
            vector<int> line;
            int len = q.size();

            while (len--) {
                auto t = q.front();
                q.pop();
                line.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (flag) reverse(line.begin(), line.end());
            flag = !flag;
            res.push_back(line);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

