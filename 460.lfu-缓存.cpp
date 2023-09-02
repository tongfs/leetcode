/*
 * @lc app=leetcode.cn id=460 lang=cpp
 * @lcpr version=21910
 *
 * [460] LFU 缓存
 */
#include "mylib.h"
// @lc code=start
class LFUCache {
public:
    LFUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if (!node_map.count(key)) return -1;
        auto p = node_map[key];
        remove(p);
        p->freq++;
        insert(p);
        if (freq_map[min_freq]->empty()) min_freq++;
        return p->val;
    }
    
    void put(int key, int val) {
        if (sz == 0) return;
        if (get(key) != -1) {
            node_map[key]->val = val;
        } else {
            if (node_map.size() == sz) {
                auto t = freq_map[min_freq]->tail->left;
                remove(t);
                node_map.erase(t->key);
                delete(t);
            }
            auto p = new Node(key, val);
            insert(p);
            node_map[key] = p;
            min_freq = 1;
        }
    }

private:
    struct Node {
        int freq;
        int key, val;
        Node *left, *right;

        Node() : freq(0) {}

        Node(int key, int val) : key(key), val(val), freq(1) {}
    };

    struct Block {
        int freq;
        Node *head, *tail;

        bool empty() {
            return head->right == tail;
        }

        Block(int freq) : freq(freq), head(new Node()), tail(new Node()) {
            head->right = tail;
            tail->left = head;
        }
    };

    int sz;
    int min_freq;
    unordered_map<int, Node*> node_map;
    unordered_map<int, Block*> freq_map;

    void insert(Node* p) {
        int freq = p->freq;
        if (!freq_map.count(freq)) freq_map[freq] = new Block(freq);
        auto block = freq_map[freq];
        p->right = block->head->right;
        p->right->left = p;
        p->left = block->head;
        block->head->right = p;
    }

    void remove(Node* p) {
        p->left->right = p->right;
        p->right->left = p->left;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



/*
// @lcpr case=start
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"][[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]\n
// @lcpr case=end

 */

