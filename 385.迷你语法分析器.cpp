/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

#include "mylib.h"

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int u = 0;
        return dfs(s, u);  
    }

    NestedInteger dfs(string& s, int& u) {
        NestedInteger res;
        if (s[u] == '[') {
            ++ u;
            while (s[u] != ']') res.add(dfs(s, u));
            ++ u;
            if (u < s.size() && s[u] == ',') ++ u;
        } else {
            int k = u;
            while (u< s.size() && s[u] != ',' && s[u] != ']') ++ u;
            res.setInteger(stoi(s.substr(k, u - k)));
            if (u < s.size() && s[u] == ',') ++ u;
        }
        return res;
    }
};
// @lc code=end

