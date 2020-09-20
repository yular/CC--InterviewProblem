/*
*
* Tag: Sweep Line
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        if(requests.size() == 0 || nums.size() == 0) {
            return 0;
        }
        
        int n = nums.size();
        vector<int> cnt(n, 0);
        for(vector<int> req : requests){
            ++ cnt[req[0]];
            if(req[1] < n - 1) {
                -- cnt[req[1] + 1];
            }
        }
        for(int i = 1; i < n; ++ i) {
            cnt[i] += cnt[i - 1];
        }
        
        sort(nums.begin(), nums.end());
        sort(cnt.begin(), cnt.end());
        
        long long ans = 0;
        for(int i = 0; i < n; ++ i){
            long long v = (long long)nums[i]*(long long)cnt[i];
            ans = (ans + v)%MOD;
        }
        return ans;
    }
};
