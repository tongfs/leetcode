/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i ++ ) map[inorder[i]] = i;
        return dfs(preorder, 0 ,inorder, 0, n);
    }

    TreeNode* dfs(vector<int>& preorder, int l1, vector<int>& inorder, int l2, int len) {
        if (!len) return nullptr;
        
        int t = map[preorder[l1]];

        auto res = new TreeNode(preorder[l1]);
        res->left = dfs(preorder, l1 + 1, inorder, l2, t - l2);
        res->right = dfs(preorder, l1 + t - l2 + 1, inorder, t + 1, len - (t - l2) - 1);

        return res;
    }
};
// @lc code=end

