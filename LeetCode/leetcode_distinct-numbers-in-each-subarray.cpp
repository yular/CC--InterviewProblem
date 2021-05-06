/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        if(nums.size() < k || k == 0) {
            return {};
        }
        
        int n = nums.size(), m = n - k + 1;
        vector<int> ans(m);
        unordered_map<int,int> numCnt;
        for(int i = 0, cnt = 0, j = 0; i < n; ++ i) {
            ++ numCnt[nums[i]];
            if(i < k - 1) {
                continue;
            }
            ans[j ++] = (int)numCnt.size();
            -- numCnt[nums[j - 1]];
            if(numCnt[nums[j - 1]] == 0) {
                numCnt.erase(nums[j - 1]);
            }
        }
        return ans;
    }
};
