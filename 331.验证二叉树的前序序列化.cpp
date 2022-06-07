/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        // return dfs1(preorder, u, a, b);
        int u = 0;
        string s = preorder + ',';
        return dfs2(s, u) && u == s.size();
    }

    // dfs1(): 根据节点和空节点之间的关系来判断
    // 1. preorder 的长度为 2n + 1，节点个数为 n
    // 2. 在递归的任意时刻，有效节点的数量 ≥ 空节点的数量
    bool dfs1(string& preorder, int& u, int& a, int& b) {
        if (u > preorder.size()) {
            if (a + 1 == b) return true;
            else return false;
        }
        if (a > preorder.size() / 2 || a + 1 <= b) return false;

        if (preorder[u] == '#') b ++ , u += 2;
        else {
            while (isdigit(preorder[u ++ ]));
            a ++ ;
        }

        return dfs1(preorder, u, a, b) && dfs1(preorder, u, a, b);
    }

    // dfs2():
    bool dfs2(string& s, int& u) {
        if (u == s.size()) return false;

        if (s[u] == '#') return u += 2, true;
        while (s[u ++ ] != ',');
        return dfs2(s, u) && dfs2(s, u);
    }
};
// @lc code=end

