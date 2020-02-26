/*
*
* Tag: Binary Search
* Time: O(nlgm) where m is the largest number in the array
* Space: O(1)
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int r = nums[0];
        for(int i = 1; i < nums.size(); ++ i){
            r = max(r, nums[i]);
        }
        
        int l = 1, ans = r;
        while(l <= r) {
            int mid = (l + r)>>1;
            if(isValid(nums, mid, threshold)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
private:
    bool isValid(vector<int>& nums, int div, int threshold) {
        int sum = 0;
        for(int num : nums) {
            int v = num/div;
            if(num%div != 0) {
                ++ v;
            }
            
            sum += v;
        }
        return sum <= threshold;
    }
};
