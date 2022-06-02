/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

#include "mylib.h"

// @lc code=start
class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> map;

    RandomizedCollection() {}
    
    bool insert(int x) {
        bool res = map[x].empty();
        nums.push_back(x);
        map[x].insert(nums.size() - 1);
        return res;
    }
    
    bool remove(int x) {
        if (map[x].empty()) return false;
        int y = nums.back();
        int px = *map[x].begin(), py = nums.size() - 1;
        swap(nums[px], nums[py]);
        nums.pop_back();
        map[x].erase(px), map[x].insert(py);
        map[y].erase(py), map[y].insert(px);
        map[x].erase(py);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

