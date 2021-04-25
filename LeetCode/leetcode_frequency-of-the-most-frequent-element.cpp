/*
*
* Tag: Binary Search
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        if(nums.size() == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int l = 1, r = nums.size(), ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid, nums, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
private:
    bool check(int len, vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i < len - 1; i++){
            sum += nums[i]; 
        }
        for (int i = 0, j = len - 1; j < nums.size(); j++, i++) {
            sum += nums[j];
            long long need = 1LL * nums[j] * len; 
            if (need - sum <= k) {
                return true;
            }
            sum -= nums[i];
        }
        return false;
    }
};
