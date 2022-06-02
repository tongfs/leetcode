/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

#include "mylib.h"

// @lc code=start
class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> map;

    RandomizedSet() {}
    
    bool insert(int x) {
        if (map.count(x)) return false;
        nums.push_back(x);
        map[x] = nums.size() - 1;
        return true;
    }
    
    bool remove(int x) {
        if (!map.count(x)) return false;
        int y = nums.back();
        int px = map[x], py = map[y];
        swap(map[x], map[y]);
        swap(nums[px], nums[py]);
        map.erase(x);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

