/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

#include "mylib.h"

// @lc code=start
class LRUCache {
public:
    struct DLNode {
        int key;
        int val;
        DLNode *left, *right;
        DLNode(int _key, int _val): key(_key), val(_val), left(nullptr), right(nullptr) {}
    }*L, *R;

    int n;
    unordered_map<int, DLNode*> map;

    LRUCache(int capacity) {
        n = capacity;
        L = new DLNode(-1, -1), R = new DLNode(-1, -1);
        L->right = R, R->left = L;
    }
    
    int get(int key) {
        if (!map.count(key)) return -1;

        auto p = map[key];
        remove(p);
        insert(p);

        return p->val;
    }
    
    void put(int key, int value) {
        if (!map.count(key)) {
            if (map.size() == n) {
                auto p = R->left;
                remove(p);
                map.erase(p->key);
                delete(p);
            }
            auto p = new DLNode(key, value);
            map[key] = p;
            insert(p);
        } else {
            auto p = map[key];
            p->val = value;
            remove(p);
            insert(p);
        }
    }

    void remove(DLNode* p) {
        p->left->right = p->right;
        p->right->left = p->left;
    }

    void insert(DLNode* p) {
        p->right = L->right;
        p->right->left = p;
        L->right = p;
        p->left = L;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

