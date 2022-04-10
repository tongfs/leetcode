/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include <iostream>
#include <vector>
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
    bool isValidBST(TreeNode* root) {
        return dfs(root)[0];
    }

    vector<int> dfs(TreeNode* u) {
        int minV = u->val, maxV = u->val;
        
        if (u->left) {
            auto t = dfs(u->left);
            if (!t[0] || t[2] >= u->val) return {false};
            minV = min(minV, t[1]);
        }

        if (u->right) {
            auto t = dfs(u->right);
            if (!t[0] || t[1] <= u->val) return {false};
            maxV = max(maxV, t[2]);
        }

        return {true, minV, maxV};
    }
};
// @lc code=end

