/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int countNicePairs(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        
        unordered_map<long long,int> diffCnt;
        int n = nums.size();
        long long ans = 0;
        for(int i = n - 1; i >=0; -- i){
            long long diff = nums[i] - getRev(nums[i]);
            ans += diffCnt[diff];
            ans %= MOD;
            ++ diffCnt[diff];
        }
        
        return ans;
    }
private:
    long long getRev(long long v) {
        long long res = 0;
        while(v > 0) {
            res = (res * 10) + (v%10);
            v /= 10;
        }
        return res;
    }
};
