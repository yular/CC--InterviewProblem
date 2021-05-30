/*
*
* Tag: DP
* Time: O(n*(2^n))
* Space: O(n*(2^n))
* Credit: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/discuss/1239681/C%2B%2B-Simple-and-Clean-BitMask-DP
*/

class Solution {
public:    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() != nums2.size()) {
            return 0;
        }
        
        vector<vector<int>> dp(14, vector<int>(16384, -1));
        return dfs(0,0,nums1,nums2, dp);
    }
private:
    int dfs(int idx,int mask, vector<int>& nums1,vector<int>& nums2, vector<vector<int>> &dp) {
        if(idx >= nums1.size()) {
            return 0;
        }
        
        if(dp[idx][mask]!=-1) {
            return dp[idx][mask];
        }
        int res=INT_MAX;
        for(int i = 0; i < nums1.size(); ++i) {
            if((mask&(1<<i))==0) {
                res = min(res,(nums1[idx]^nums2[i]) + dfs(idx + 1, mask|1<<i, nums1, nums2, dp));
            }
        }
        return dp[idx][mask]=res;
    }
};
