/*
*
* Tag: Math
* Time: O(nm)
* Space: O(n^1.5)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
        if(queries.size() == 0) {
            return {};
        }
        
        int n = nums.size(), sqN = sqrt(n), m = queries.size();
        vector<vector<int>> sumArr(n, vector<int>(sqN + 2, 0));
        for(int i = 1; i <= sqN; ++ i) {
            for(int j = n - 1; j >= 0; -- j) {
                long long sum = nums[j];
                if(j + i < n) {
                    sum += sumArr[j + i][i];
                }
                sum %= MOD;
                sumArr[j][i] = sum;
            }
        }
        
        vector<int> ans(m, 0);
        for(int i = 0; i < m; ++ i) {
            if(queries[i][1] <= sqN) {
                ans[i] = sumArr[queries[i][0]][queries[i][1]];
                continue;
            }
            
            long long sum = 0;
            for(int j = queries[i][0]; j < n; j += queries[i][1]) {
                sum += nums[j];
                sum %= MOD;
            }
            ans[i] = sum;
        }
        return ans;
    }
};
