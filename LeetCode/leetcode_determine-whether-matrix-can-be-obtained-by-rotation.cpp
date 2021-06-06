/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), minVal = nums[0], ans = 0, tot = 0;
        for(int i = n - 1; i >= 0; -- i) {
            if(nums[i] == minVal) {
                break;
            }
            int cnt = 0, v = nums[i];
            while(i >= 0 && v == nums[i]) {
                ++ cnt, -- i;
            }
            ans += (tot + cnt);
            tot += cnt;
            ++ i;
        }
        
        return ans;
    }
};
