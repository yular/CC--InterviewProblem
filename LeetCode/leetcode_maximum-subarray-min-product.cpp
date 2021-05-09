/*
*
* Tag: Mono Stack
* Time: O(n)
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
        
        vector<int> stk(n, 0);
        int ans = 0, top = 0;
        long long maxVal = 0;
        for(int i = 0; i <= n; ++ i) {
            long long v = -1;
            if(i < n) {
                v = nums[i];
            }
            while(top > 0) {
                if(nums[stk[top - 1]] > v) {
                    long long rbs = sum[i - 1], lbs = 0;
                    if(top >= 2) {
                        lbs = sum[stk[top - 2]];
                    }
                    long long cur = nums[stk[top - 1]]*(rbs - lbs);
                    if(cur > maxVal) {
                        maxVal = cur;
                        ans = maxVal%MOD;
                    }
                    -- top;
                } else {
                    break;
                }
            }
            stk[top ++] = i;
        }
        return ans;
    }
};
