/*
*
* Tag: Math
* Time: O(nlgn + n^2 * lgn)
* Space: O(n)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        long long ans = 0, sum = 0;
        for(int i = 0; i < n; ++ i) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                ans += sum;
                ans %= MOD;
                continue;
            }
            
            sum = 0;
            for(long long j = 1; ; ) {
                int l = lower_bound(nums.begin()+i,nums.end(),nums[i]*j)-nums.begin();
                int r = lower_bound(nums.begin()+l,nums.end(),nums[i]*(j+1))-nums.begin();
                sum = (sum + j*(r-l))%MOD;
                if(r == n) {
                    break;
                }
                j = (long long)nums[r]/nums[i];
            }
            ans += sum;
            ans %= MOD;
        }
        return ans;
    }
};


// Credit: https://leetcode.com/problems/sum-of-floored-pairs/discuss/1212352/(C%2B%2B)-1862.-Sum-of-Floored-Pairs
class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int m = *max_element(nums.begin(), nums.end()); 
        vector<long> vals(m+1); 
        for (auto x : nums) 
            ++vals[x]; 
        
        for (int x = m; x > 0; --x) 
            for (int xx = 2*x; xx <= m; xx += x) 
                vals[xx] += vals[x]; 
        
        for (int i = 1; i < vals.size(); ++i) 
            vals[i] += vals[i-1]; 
        
        int ans = 0; 
        for (auto x : nums) 
            ans = (ans + vals[x]) % MOD; 
        return ans; 
    }
};
