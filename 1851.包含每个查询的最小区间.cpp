/*
 * @lc app=leetcode.cn id=1851 lang=cpp
 * @lcpr version=21910
 *
 * [1851] 包含每个查询的最小区间
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();
        sort(intervals.begin(), intervals.end());

        using PII = pair<int, int>;
        vector<PII> index(m);
        for (int i = 0; i < m; i++) index[i] = {queries[i], i};
        sort(index.begin(), index.end());
        
        vector<int> res(m, -1);
        priority_queue<PII, vector<PII>, greater<PII>> heap;

        for (int i = 0, k = 0; i < m; i++) {
            int x = index[i].first, y = index[i].second;
            while (k < n && intervals[k][0] <= x) {
                int l = intervals[k][0], r = intervals[k][1];
                heap.push({r - l + 1, r});
                k++;
            }
            while (heap.size() && heap.top().second < x) heap.pop();
            if (heap.size()) res[y] = heap.top().first;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[2,4],[3,6],[4,4]]\n[2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3],[2,5],[1,8],[20,25]]\n[2,19,5,22]\n
// @lcpr case=end

 */

