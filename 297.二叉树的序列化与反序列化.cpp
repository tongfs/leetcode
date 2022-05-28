/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:
    int u = 0;
    string path;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs_s(root);
        return path;
    }

    void dfs_s(TreeNode* root) {
        if (!root) {
            path += "#,";
            return;
        }

        path += to_string(root->val) + ",";
        dfs_s(root->left);
        dfs_s(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dfs_d(data);
    }

    TreeNode* dfs_d(string& data) {
        if (data[u] == '#') {
            u += 2;
            return nullptr;
        }

        int k = u;
        while (u < data.size() && data[u] != ',') u ++ ;
        auto root = new TreeNode(stoi(data.substr(k, u - k)));
        u ++ ;
        root->left = dfs_d(data);
        root->right = dfs_d(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

