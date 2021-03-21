/*
*
* Tag: DFS
* Time: O(n^14)
* Space: O(n^2)
*/

class Solution {
private:
    struct chainComparator{
        bool operator() (const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        }
    }cmp;
public:
    int maxScore(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        
        int tot = 2<<16, ans = 0, n = nums.size();
        vector<vector<int>> stateList;
        vector<int> maxVal(tot, -1);
        for(int i = 0; i < n; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                int v = gcd(nums[i], nums[j]);
                int state = ((1<<i)|(1<<j));
                maxVal[state] = max(maxVal[state], v);
                stateList.push_back({state, v});
            }
        }
        
        sort(stateList.begin(), stateList.end(), cmp);
        
        dfs(maxVal,stateList, ans, 0, 0, 0, 0, n/2);
        return ans;
    }
    
private:
    void dfs(vector<int> &maxVal, vector<vector<int>> &stateList, int &ans, int state, int sum, int dep, int startIdx, int tot) {
        if(dep >= tot) {
            ans = max(ans, sum);
            maxVal[state] = ans;
            return ;
        }
        if(maxVal[state] > sum) {
            return ;
        }
        maxVal[state] = sum;
        
        for(int i = startIdx; i < stateList.size(); ++ i) {
            int nxtState = stateList[i][0], nxtVal = stateList[i][1];
            if((state&nxtState) > 0) {
                continue;
            }
            
            int v = (dep + 1)*nxtVal;
            dfs(maxVal,stateList, ans, (state|nxtState), sum + v, dep + 1, i + 1, tot);
        }
        return ;
    }
};
