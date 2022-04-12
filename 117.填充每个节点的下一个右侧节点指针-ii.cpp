/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

#include "mylib.h"

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        auto p = root;
        while (p) {
            auto head = new Node(-1), tail = head;
            while (p) {
                if (p->left) tail = tail->next = p->left;
                if (p->right) tail = tail->next = p->right;
                p = p->next;
            }
            p = head->next;
        }
        return root;
    }
};
// @lc code=end

