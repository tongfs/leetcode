/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string s;
    vector<string> res;

    vector<string> removeInvalidParentheses(string _s) {
        /*
         * l: 要删除的左括号的数量
         * r: 要删除的右括号的数量
         * */
        s = _s;
        int l = 0, r = 0;
        for (auto c: s) {
            if (c == '(') l ++ ;
            else if ( c== ')') {
                if (!l) r ++ ;
                else l -- ;
            }
        }

        dfs(0, "", 0, l, r);
        return res;
    }

    /* 
     * u: 当前枚举到第几个字符
     * path: 枚举到u时的路径
     * cnt: path中左括号比右括号多多少个
     * l: 还要删除几个左括号
     * r: 还要删除几个右括号
     */
    void dfs(int u, string path, int cnt, int l, int r) {
        if (u == s.size()) {
            if (!cnt) res.push_back(path);
            return;
        }

        if (s[u] != '(' && s[u] != ')') {
            dfs(u + 1, path + s[u], cnt, l, r);
        } else if (s[u] == '(') {
            int k = u;
            while (k < s.size() && s[k] == '(') k ++ ;
            l -= k - u;
            for (int i = k - u; i >= 0; i -- ) {
                if (l >= 0) dfs(k, path, cnt, l, r);
                path.push_back('(');
                l ++ , cnt ++ ;
            }
        } else {
            int k = u;
            while (k < s.size() && s[k] == ')') k ++ ;
            r -= k - u;
            for (int i = k - u; i >= 0; i -- ) {
                if (cnt >= 0 && r >= 0) dfs(k, path, cnt, l, r);
                path.push_back(')');
                r ++ , cnt -- ;
            }
        }
    }
};
// @lc code=end

