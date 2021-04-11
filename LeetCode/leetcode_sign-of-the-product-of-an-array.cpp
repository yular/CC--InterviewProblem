/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int negCnt = 0;
        for(int num : nums) {
            if(num == 0) {
                return 0;
            }
            if(num < 0) {
                ++ negCnt;
            }
        }
        return (negCnt&1) == 0? 1 : -1;
    }
};
