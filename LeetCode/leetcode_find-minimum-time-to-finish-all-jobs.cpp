/*
*
* Tag: DFS
* Time: O(nlgn + k^(n - k))
* Space: O(k)
*/

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        if(k == 0) {
            return -1;
        }
        
        sort(jobs.begin(), jobs.end());
        
        vector<int> wk(k, 0);
        int ans = INT_MAX, n = jobs.size(), maxVal = 0;
        for(int i = n - 1, j = 0; j < k && i >= 0; --i, ++ j) {
            wk[j] = jobs[i];
            maxVal = max(maxVal, wk[j]);
        }
        if(k >= n) {
            return maxVal;
        }
        
        dfs(jobs, 0, n - k, wk, k, maxVal, ans);
        return ans;
    }
private:
    void dfs(vector<int>& jobs, int idx, int n, vector<int> &wk, int k, int curMax, int &ans) {
        if(idx >= n) {
            ans = min(curMax, ans);
            return ;
        }
        if(curMax >= ans) {
            return ;
        }
        
        for(int i = 0; i < k; ++ i) {
            wk[i] += jobs[idx];
            dfs(jobs, idx + 1, n, wk, k, max(curMax, wk[i]), ans);
            wk[i] -= jobs[idx];
        }
        return ;
    }
};
