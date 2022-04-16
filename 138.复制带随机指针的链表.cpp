/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start
class Solution {
public:
    Node* copyRandomList(Node* head) {
        return method2(head);
    }

    // 解法一：用哈希表，空间复杂度O(n)
    Node* method1(Node* head) {
        unordered_map<Node*, Node*> map;

        for (Node *p = head, *pre_q = nullptr; p; p = p->next) {
            auto q = new Node(p->val);
            if (pre_q) pre_q->next = q;
            map[p] = pre_q = q;
        }

        for (auto p = head; p; p = p->next)
            map[p]->random = map[p->random];

        return map[head];
    }
    
    // 解法二：不用哈希表，空间复杂度O(1)
    Node* method2(Node* head) {
        // 复制小弟到自己后面
        for (auto p = head; p; p = p->next->next) {
            auto q = new Node(p->val);
            q->next = p->next;
            p->next = q;

        }

        // 复制random
        for (auto p = head; p; p = p->next->next)
            if (p->random)
                p->next->random = p->random->next;

        // 拆分成两个链表
        auto dummy = new Node(-1), tail = dummy;
        for (auto p = head; p; p = p->next) {
            auto q = p->next;
            tail = tail->next = q;
            p->next = q->next;
        }

        return dummy->next;
    }
};
// @lc code=end

