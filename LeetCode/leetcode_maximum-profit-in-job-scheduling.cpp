/*
*
* Tag: DP
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        if(startTime.size() == 0 || endTime.size() == 0 || profit.size() == 0) {
            return 0;
        }
        
        int n = profit.size();
        set<int> timeList;
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for(int i = 0; i < n; ++ i) {
            timeList.insert(startTime[i]);
            timeList.insert(endTime[i]);
            
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        int idx = 1;
        unordered_map<int,int> timeDict;
        for(int t : timeList) {
            timeDict[t] = idx ++;
        }
        
        sort(jobs.begin(), jobs.end(), cmp);
        
        int ans = 0;
        vector<int> dp(n, 0), fenTree(idx + 1, 0);
        for(int i = 0; i < n; ++ i) {
            dp[i] = jobs[i][2] + getMax(fenTree, timeDict[jobs[i][0]]);
            updateTree(fenTree, timeDict[jobs[i][1]], dp[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
private:
    int getMax(vector<int> &fenTree, int startIdx) {
        int res = 0;
        for(int i = startIdx; i > 0; i -= lowbit(i)) {
            res = max(res, fenTree[i]);
        }
        return res;
    }
    
    void updateTree(vector<int> &fenTree, int startIdx, int v) {
        int n = fenTree.size();
        for(int i = startIdx; i < n; i += lowbit(i)) {
            fenTree[i] = max(fenTree[i], v);
        }
        return ;
    }
    
    int lowbit(int x) {
        return x&-x;
    }
    
    struct comparator {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            if(a[0] == b[0]) {
                return a[1] == b[1] ? b[0] < a[0] : a[1] < b[1];
            }
            return a[0] < b[0];
        }
    }cmp;
};
