/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() == 0) {
            return 0;
        }
        
        vector<unordered_map<int,int>> numIdx(2);
        numIdx[0].clear();
        for(int i = 0; i < nums1.size(); ++ i) {
            numIdx[0][nums1[i]] = i;
        }
        numIdx[1].clear();
        for(int i = 0; i < nums2.size(); ++ i) {
            numIdx[1][nums2[i]] = i;
        }
        
        vector<vector<long long>> dp(2);
        dp[0].resize(nums1.size());
        dp[1].resize(nums2.size());
        init(dp);
        
        vector<vector<int>> nums;
        nums.push_back(nums1);
        nums.push_back(nums2);
        
        long long ans = dfs(0, 0, dp, numIdx, nums, true);
        
        ans = max(ans, dfs(1, 0, dp, numIdx, nums, true));
        return ans%MOD;
    }
private:
    void init(vector<vector<long long>> &dp) {
        fill(dp[0].begin(), dp[0].end(), -1);
        fill(dp[1].begin(), dp[1].end(), -1);
    }
    
    long long dfs(int curArr, int idx, vector<vector<long long>> &dp, vector<unordered_map<int,int>> &numIdx, vector<vector<int>> &nums, bool canSwitch) {
        if(idx >= nums[curArr].size()) {
            return 0;
        }
        
        if(dp[curArr][idx] != -1) {
            return dp[curArr][idx];
        }
        
        long long &res = dp[curArr][idx], v = nums[curArr][idx];
        res = v + dfs(curArr, idx + 1, dp, numIdx, nums, true);
        int nxtArr = (curArr + 1)%2;
        if(numIdx[nxtArr].count(v) == 0) {
            return res;
        }
        
        int nxtIdx = numIdx[nxtArr][v];
        if(canSwitch) {          
            res = max(res, dfs(nxtArr, nxtIdx, dp, numIdx, nums, false) );
        } else {
            if(nxtIdx + 1 < nums[nxtArr].size()) {
                v += dp[nxtArr][nxtIdx + 1];
            }
            res = max(res, v);
        }
        
        return res;
    }
};
