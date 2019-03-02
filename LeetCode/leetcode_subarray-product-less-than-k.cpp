/*
*
* Tag: Sliding Window
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        if(nums.size() == 0 || k == 0){
            return ans;
        }
        
        long long v = 1;
        for(int first = 0, last = 0; last < nums.size(); ++ last) {
            v *= nums[last];
            while(v >= k && first <= last){
                v /= nums[first];
                ++ first;
            }
            
            if(v < k && first <= last) {
                ans += (last - first + 1);
            }
        }
        return ans;
    }
};
