/*
*
* Tag: DFS
* Time: O(n*2^m)
* Space: O(m)
*/

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        if(baseCosts.size() == 0 || target <= 0) {
            return 0;
        }
        
        sort(baseCosts.begin(), baseCosts.end());
        sort(toppingCosts.begin(), toppingCosts.end());
        
        int ans = 0, maxDif = 2e9, n = baseCosts.size(), m = toppingCosts.size();
        for(int i = n - 1; i >= 0; -- i) {
            dfs(ans, maxDif, baseCosts[i], target, m, toppingCosts);
            if(maxDif == 0) {
                break;
            }
        }
        return ans;
    }
private:
    void dfs(int &ans, int &maxDif, int sum, int target, int idx, vector<int>& toppingCosts) {
        int curDif = abs(sum - target);
        if(curDif > maxDif && sum > target) {
            return ;
        }
        if(curDif <= maxDif) {
            ans = sum;
            maxDif = abs(sum - target);
        }
        if(idx <= 0) {
            return ;
        }
        
        for(int i = idx - 1; i >= 0; -- i) {
            for(int j = 2; j >= 0; -- j) {
                dfs(ans, maxDif, sum + j*toppingCosts[i], target, i, toppingCosts);
                if(maxDif == 0) {
                    return ;
                }
            }
        }
        return ;
    }
};
