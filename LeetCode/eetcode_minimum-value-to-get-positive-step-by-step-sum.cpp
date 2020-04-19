/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        if(nums.size() == 0) {
            return 1;
        }
        
        int sum = 0, minval = INT_MAX;
        for(int num : nums) {
            sum += num;
            minval = min(minval, sum);
        }
        return minval < 0? -minval + 1 : 1;
    }
};
