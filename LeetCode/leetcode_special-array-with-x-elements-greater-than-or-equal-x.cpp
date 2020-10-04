/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        if(nums.size() == 0) {
            return -1;
        }
        
        int n = nums.size();
        for(int x = 1; x <= n; ++ x) {
            int cnt = 0;
            for(int j = 0; j < n; ++ j) {
                if(nums[j] >= x) {
                    ++ cnt;
                }
            }
            if(cnt == x) {
                return x;
            }
        }
        return -1;
    }
};
