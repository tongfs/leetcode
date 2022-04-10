/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        iteration(root);
        return res; 
    }

    // 解法一：递归
    void dfs(TreeNode* u) {
        if (!u) return;
        dfs(u->left);
        res.push_back(u->val);
        dfs(u->right);
    }

    // 解法二：迭代
    void iteration(TreeNode* root) {
        stack<TreeNode*> stk;
        while (root || stk.size()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }
};
// @lc code=end

