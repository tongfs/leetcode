/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> map;
        for (int i = 0; i < arr2.size(); i ++ )
            map[arr2[i]] = i - arr2.size();

        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if (map[a] == map[b]) return a < b;
            return map[a] < map[b];
        });

        return arr1;
    }
};
// @lc code=end

