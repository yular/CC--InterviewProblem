/*
*
* Tag: Binary Search
* Time: O(ngln)
* Space: O(n)
*/

class Solution {
private:
    const long long MOD = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        if(nums.size() < 2) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        long long ans = 0;
        unordered_map<int,long long> dic = {{0, 1}, {1, 2}};
        for(int l = 0; l < nums.size(); ++ l) {
            if(nums[l] >= target) {
                break;
            }
            int r = upper_bound(nums.begin(), nums.end(), target - nums[l]) - nums.begin() - 1;
            if(r >= l) {
                ans = (ans + getFastPow(dic, r - l))%MOD;
            }
        }
        return ans;
    }
    
private:
    long long getFastPow(unordered_map<int,long long> &dic, int p) {
        if(dic.count(p) > 0) {
            return dic[p];
        }
        
        long long res = 1, factor = 2;
        for(int mask = 1; mask <= p; mask <<= 1) {
            if((mask&p) > 0) {
                res *= factor;
                res %= MOD;
            }
            factor = (factor*factor)%MOD;
        }
        dic[p] = res;
        return res;
    }
};
