/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        if(nums.size() != index.size()) {
            return nums;
        }
        
        vector<int> ans(nums.begin(), nums.end());
        for(int i = 0; i < index.size(); ++ i) {
            int idx = index[i];
            for(int j = nums.size() - 1; j > idx; -- j) {
                ans[j] = ans[j - 1];
            }
            
            ans[idx] = nums[i];
        }
        return ans;
    }
};
