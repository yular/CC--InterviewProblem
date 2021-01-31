/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        if(candiesCount.size() == 0) {
            return {};
        }
        
        int n = candiesCount.size(), m = queries.size();
        vector<long long> prefix(n, candiesCount[0]);
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + candiesCount[i];
        }
        
        vector<bool> ans(m, 0);
        for(int i = 0; i < queries.size(); ++ i){
            long long idx = queries[i][0], d = queries[i][1], cap = queries[i][2];
            long long maxD = prefix[idx] - 1, minD = idx == 0? 0 : prefix[idx - 1]/cap;
            
            if(d >= minD && d <= maxD) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
          }

          return ans;
    }
};
