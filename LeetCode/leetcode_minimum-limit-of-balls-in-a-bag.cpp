/*
*
* Tag: Binary Search
* Time: O(n*lgMaxVal)
* Space: O(1)
*/

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int r = nums[0];
        for(int num : nums) {
            r = max(r, num);
        }
        
        int ans = 0, l = 1;
        while(l <= r) {
            int mid = (l + r)>>1;
            if(isValid(mid, nums, maxOperations)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
private:
    bool isValid(int v, vector<int>& nums, int ops) {
        int cnt = 0;
        for(int num : nums) {
            cnt += (num - 1)/v;
            if(cnt > ops) {
                return false;
            }
        }
        return cnt <= ops;
    }
};
