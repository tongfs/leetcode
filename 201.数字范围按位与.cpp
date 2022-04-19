/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        for (int i = 0; i < 31; i ++ )
            if ((left >> i) == (right >> i))
                return left >> i << i;
        return 0;
    }
};
// @lc code=end

