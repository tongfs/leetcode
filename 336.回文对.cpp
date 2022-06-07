/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    typedef unsigned long long ULL;

    const int N = 310, P = 131;

    vector<ULL> p;
    vector<vector<ULL>> h1, h2;

    vector<vector<int>> palindromePairs(vector<string>& words) {
        p = vector<ULL>(N);
        p[0] = 1;
        for (int i = 1; i < N; i ++ ) p[i] = p[i - 1] * P;

        for (int i = 0; i < words.size(); i ++ ) {
            auto word = words[i];
            int n = word.size();
            vector<ULL> a(1), b(1);
            for (int j = 1; j <= n; j ++ ) a.push_back(a.back() * P + word[j - 1]);
            for (int j = n; j >= 1; j -- ) b.push_back(b.back() * P + word[j - 1]);
            h1.push_back(a);
            h2.push_back(b);
        }

        unordered_map<ULL, int> map;
        for (int i = 0; i < words.size(); i ++ )
            map[get(h2[i], 1, words[i].size())] = i;

        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++ ) {
            auto word = words[i];
            int n = word.size();
            for (int j = 0; j <= n; j ++ ) {
                auto left = get(h1[i], 1, j), right = get(h1[i], j + 1, n);
                if (right == get(h2[i], 1, n - j) && map.count(left) && map[left] != i)
                    res.push_back({i, map[left]});
                if (left == get(h2[i], n - j + 1, n) && map.count(right) && map[right] != i && word.size() != words[map[right]].size())
                    res.push_back({map[right], i});
            }
        }
        return res;
    }

private:
    ULL get(vector<ULL>& h, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
};
// @lc code=end

