/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

#include "mylib.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // 解法一：先将链表转换为数组，后面和108题一样
    // 解法二：直接用链表
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode *lpre, *p = head;

        int cnt = 0;
        while (p) p = p->next, cnt ++ ;

        p = head;
        for (int i = 0; i < cnt / 2; i ++ ) lpre = p, p = p->next;
        lpre->next = nullptr;

        auto res = new TreeNode(p->val);
        res->left = sortedListToBST(head);
        res->right = sortedListToBST(p->next);

        return res;
    }
};
// @lc code=end

