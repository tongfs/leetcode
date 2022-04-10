/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

#include <iostream>
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
    TreeNode *p, *q, *pre;

    void recoverTree(TreeNode* root) {
        inorder_traversal(root);
    }

    // 解法一：中序遍历
    void inorder_traversal(TreeNode* root) {
        stack<TreeNode*> stk;
        while (root || stk.size()) {
            while (root) {
                stk.push(root); 
                root = root->left;
            }
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
        swap(p->val, q->val);
    }

    // 解法二：Morris遍历
    /*
     * 1. 如果root没有左子树，则直接遍历该节点，然后遍历右子树
     * 2. 如果root有左子树，则找到root的前驱节点t
     *      若t->right==NULL，则t->right=root，然后遍历左子树
     *      否则，令t->right=NULL，遍历root，然后遍历右子树
     */
    void morris(TreeNode* root) {
        while (root) {
            if(!root->left) {
                if (pre && pre->val > root->val) {
                    if (!p) p = pre, q = root;
                    if (pre && pre->val > root->val) {
                        if (!p) p = pre, q = root;
                        else q = root;  // 不懂这里为什么不能直接break
                    }
                }
                pre = root;
                root = root->right;
            } else {
                auto t = root->left;
                while (t->right && t->right != root) t = t->right;
                if (!t->right) t->right = root, root = root->left;
                else {
                    t->right = NULL;
                    if (pre && pre->val > root->val) {
                        if (!p) p = pre, q = root;
                        else q = root;
                    }
                    pre = root;
                    root = root->right;
                }
            }
        }
        swap(p->val, q->val);
    }
};
// @lc code=end

