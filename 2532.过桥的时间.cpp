/*
 * @lc app=leetcode.cn id=2532 lang=cpp
 * @lcpr version=21910
 *
 * [2532] 过桥的时间
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        using PII = pair<int, int>;
        auto cmp = [&](int x, int y) {
            int time_x = time[x][0] + time[x][2];
            int time_y = time[y][0] + time[y][2];
            return time_x == time_y ? x < y : time_x < time_y;
        };

        priority_queue<int, vector<int>, decltype(cmp)> wait_left(cmp), wait_right(cmp);
        priority_queue<PII, vector<PII>, greater<PII>> work_left, work_right;

        int remain = n, cur_time = 0;
        for (int i = 0; i < k; i++) wait_left.push(i);

        while (remain || work_right.size() || wait_right.size()) {
            while (work_left.size() && work_left.top().first <= cur_time) {
                wait_left.push(work_left.top().second);
                work_left.pop();
            }
            while (work_right.size() && work_right.top().first <= cur_time) {
                wait_right.push(work_right.top().second);
                work_right.pop();
            }

            if (wait_right.size()) {
                int i = wait_right.top();
                wait_right.pop();
                cur_time += time[i][2];
                work_left.push({cur_time + time[i][3], i});
            } else if (remain && wait_left.size()) {
                int i = wait_left.top();
                wait_left.pop();
                cur_time += time[i][0];
                work_right.push({cur_time + time[i][1], i});
                remain--;
            } else {
                int next_time = INT_MAX;
                if (work_left.size()) next_time = min(next_time, work_left.top().first);
                if (work_right.size()) next_time = min(next_time, work_right.top().first);
                if (next_time != INT_MAX) cur_time = next_time;
            }
        }

        return cur_time;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n3\n[[1,1,2,1],[1,1,3,1],[1,1,4,1]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n[[1,9,1,8],[10,10,10,10]]\n
// @lcpr case=end

 */

