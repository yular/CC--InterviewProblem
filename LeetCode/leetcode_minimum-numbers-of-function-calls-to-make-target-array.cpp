/*
*
* Tag: Math
* Time: O(nlgm) m is average of number in given array
* Space: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int bitOneCnt = 0, maxPow2Cnt = 0;
        for(int num : nums) {
            int pow2Cnt = 0;
            while(num > 0) {
                bitOneCnt += (num&1);
                num >>= 1;
                ++ pow2Cnt;
            }
            
            maxPow2Cnt = max(maxPow2Cnt, pow2Cnt - 1);
        }
        return bitOneCnt + maxPow2Cnt;
    }
};
