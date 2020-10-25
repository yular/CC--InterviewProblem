/*
*
* Tag: Sort
* Time: O(mnlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        if(nums.size() == 0 || l.size() == 0 || l.size() != r.size()) {
            return {};
        }
        
        int n = nums.size(), m = l.size();
        vector<bool> ans(m, true);
        for(int i = 0; i < m; ++ i) {
            int len = r[i] - l[i] + 1;
            vector<int> arr(len, 0);
            for(int j = l[i], idx = 0; j <= r[i]; ++ j, ++ idx) {
                arr[idx] = nums[j];
            }
            
            sort(arr.begin(), arr.end());
            int diff = arr[1] - arr[0]; 
            for(int j = 1; j < len; ++ j) {
                if(arr[j] - arr[j - 1] != diff) {
                    ans[i] = false;
                    break;
                }
            }
        }
        return ans;
    }
};
