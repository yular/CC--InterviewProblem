/*
*
* Tag: DFS + Bit Manipulation
* Time: O(N + N^k) N is nCm, m = n/k
* Space: O(N)
*/

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        if(k > nums.size()) {
            return -1;
        }
        if(k == nums.size()) {
            return 0;
        }
        
        vector<int> numCnt(20, 0);
        for(int num : nums) {
            ++ numCnt[num];
            if(numCnt[num] > k) {
                return -1;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        vector<bool> vis(20, false);
        unordered_map<int,int> dict;
        int n = nums.size(), m = n/k;
        for(int i = 0; i < n; ++ i) {
            int mask = (1<<i), minV = nums[i], maxV = nums[i];
            vis[nums[i]] = true;
            preCalculate(mask, 1, i, dict, nums, m, minV, maxV, vis);
            vis[nums[i]] = false;
        }
        vector<pair<int,int>> arr(dict.size());
        int i = 0;
       for(pair<int,int> d : dict) {
           arr[i ++] = d;
       }
        
        int ans = INT_MAX, completeSet = 1<<n;
        solve(ans, completeSet, arr, -1, 0, 0, k, 0);
        return ans;
    }
    
private:
    void preCalculate(int &mask, int cnt, int idx, unordered_map<int,int>& dict, vector<int>& nums, int tot, int minV, int maxV, vector<bool> &vis) {
        if(cnt >= tot) {
            dict[mask] = maxV - minV;
            return ;
        }
        
        int n = nums.size();
        for(int i = idx + 1; i < n; ++ i) {
            if(vis[nums[i]]) {
                continue;
            }
            
            vis[nums[i]] = true;
            int nxtMask = mask | (1<<i), nxtMin = min(minV, nums[i]), nxtMax = max(maxV, nums[i]);
            preCalculate(nxtMask, cnt + 1, i, dict, nums, tot, nxtMin, nxtMax, vis);
            vis[nums[i]] = false;
        }
        return ;
    }
    
    void solve(int &ans, int &completeSet, vector<pair<int,int>> &arr, int idx, int cur, int dep, int k, int sum) {
        if(sum >= ans) {
            return ;
        }
        if(dep >= k) {
            ans = min(ans, sum);
            return ;
        }
        
        for(int i = idx + 1; i < arr.size(); ++ i) {
            int s = arr[i].first, v = arr[i].second;
            if((cur&s) > 0) {
                continue;
            }
            
            solve(ans, completeSet, arr, i, (cur|s), dep + 1, k, sum + v);
        }
        
        return ;
    }
};
