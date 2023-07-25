/*
 * @lc app=leetcode.cn id=692 lang=cpp
 * @lcpr version=21910
 *
 * [692] 前K个高频单词
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (auto& word : words) map[word]++;

        using PSI = pair<string, int>;
        auto cmp = [&](const PSI& a, const PSI& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        priority_queue<PSI, vector<PSI>, decltype(cmp)> heap(cmp);
        for (auto& it : map) {
            heap.push(it);
            if (heap.size() > k) heap.pop();
        }

        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = heap.top().first;
            heap.pop();
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["i", "love", "leetcode", "i", "love", "coding"]\n2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

