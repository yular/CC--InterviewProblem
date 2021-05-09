/*
*
* Tag: Sort + Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int n = nums.size();
        vector<long long> sum(n, nums[0]);
        for(int i = 1; i < n; ++ i) {
            sum[i] = sum[i - 1] + nums[i];
        }
        
        vector<vector<int>> numVec(n);
        for(int i = 0; i < n; ++ i) {
            numVec[i] = {nums[i], i};
        }
        sort(numVec.begin(), numVec.end());
        
        map<int,int> dict;
        dict[n - 1] = 0;
        
        int ans = 0;
        long long maxVal = 0;
        for(int i = 0; i < n; ++ i) {
            long long v = numVec[i][0];
            auto it = dict.lower_bound(numVec[i][1]);
            int rb = it->first, lb = it->second;
            long long s = sum[rb];
            if(lb > 0) {
                s -= sum[lb - 1];
            }
            if(v*s > maxVal) {
                maxVal = v*s;
                ans = maxVal % MOD;
            }
            if(numVec[i][1] < rb) {
                dict[rb] = numVec[i][1] + 1;
            }
            if(numVec[i][1] > lb) {
                dict[numVec[i][1] - 1] = lb;
            }
        }
        return ans;
    }
};
