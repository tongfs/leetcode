/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=21910
 *
 * [146] LRU 缓存
 */
#include "mylib.h"
// @lc code=start
class LRUCache {
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        L = new Node(-1, -1), R = new Node(-1, -1);
        L->right = R, R->left = L;
    }

    int get(int key) {
        if (!map.count(key)) return -1;

        auto t = map[key];
        remove(t);
        insert(t);

        return t->val;
    }

    void put(int key, int value) {
        if (!map.count(key)) {
            if (map.size() == capacity) {
                auto t = R->left;
                remove(t);
                map.erase(t->key);
                delete(t);
            }
            auto p = new Node(key, value);
            map[key] = p;
            insert(p);
        } else {
            auto p = map[key];
            p->val = value;
            remove(p);
            insert(p);
        }
    }

private:
    int capacity;

    struct Node {
        int key, val;
        Node *left, *right;
        Node(int k, int v) : key(k), val(v), left(nullptr), right(nullptr) {}
    } *L, *R;

    unordered_map<int, Node *> map;

    void remove(Node* p) {
        p->left->right = p->right;
        p->right->left = p->left;
    }

    void insert(Node* p) {
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
