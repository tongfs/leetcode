/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
class Solution {
public:
    Node* cloneGraph(Node* node) {
        return method2(node);
    }

    // 解法一：BFS
    Node* bfs(Node* node) {
        if (!node) return nullptr;

        queue<Node*> q;
        unordered_set<Node*> S; // 记录已经进入过队列里的点
        unordered_map<Node*, Node*> map;    // 旧点和新点的映射

        q.push(node);
        S.insert(node);

        while (q.size()) {
            auto t = q.front();
            q.pop();

            vector<Node*> new_neis;
            for (auto& nei : t->neighbors) {
                if (!map.count(nei)) {
                    auto new_node = new Node(nei->val);
                    map[nei] = new_node;
                    new_neis.push_back(new_node);
                } else {
                    new_neis.push_back(map[nei]);
                }

                if (!S.count(nei)) {
                    q.push(nei);
                    S.insert(nei);
                }
            }

            if (!map.count(t)) {
                auto new_head = new Node(t->val, new_neis);
                map[t] = new_head;
            } else {
                map[t]->neighbors = new_neis;
            }
        }

        return map[node];
    }

    // 解法二：DFS
    unordered_map<Node*, Node*> map;
    Node* method2(Node* node) {
        if (!node) return nullptr;
        
        dfs(node);

        // 复制所有边
        for (auto item: map)
            for (auto ver: item.first->neighbors)
                item.second->neighbors.push_back(map[ver]);

        return map[node];
    }

    // 通过DFS复制所有点
    void dfs(Node* node) {
        map[node] = new Node(node->val);
        for (auto ver: node->neighbors)
            if (!map.count(ver))
                dfs(ver);
    }
};
// @lc code=end

