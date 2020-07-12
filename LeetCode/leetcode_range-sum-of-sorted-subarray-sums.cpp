/*
*
* Tag: Sort
* Time: O((n^2)lgn)
* Space: O(n^2)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        if(n == 0 || left > right) {
            return 0;
        }
        
        int m = n*(n + 1)/2;
        vector<int> sumArr(m, 0);
        int idx = 0;
        for(int i = 0; i < n; ++ i){
            int sum = 0;
            for(int j = i; j < n; ++ j) {
                sum += nums[j];
                sumArr[idx ++] = sum;
            }
        }
        
        sort(sumArr.begin(), sumArr.end());
        
        long long ans = 0;
        for(int i = left - 1; i < right; ++ i) {
            ans += sumArr[i];
            ans %= MOD;
        }
        return ans;
    }
};
