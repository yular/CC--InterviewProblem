/*
*
* Tag: Sort + Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        if(worker.size() == 0 || difficulty.size() != profit.size() || profit.size() == 0 ) {
            return 0;
        }
        
        vector<pair<int,int>> jobs(profit.size());
        for(int i = 0; i < profit.size(); ++ i) {
            jobs[i] = make_pair(difficulty[i], profit[i]);
        }
        
        sort(jobs.begin(), jobs.end(), cmp);
        sort(worker.begin(), worker.end());
        
        int ans = 0, jit = 0, maxProfit = 0;
        for(int i = 0; i < worker.size(); ++ i) {
            while(jit < jobs.size() && jobs[jit].first <= worker[i]) {
                maxProfit = max(maxProfit, jobs[jit].second);
                ++ jit;
            }
            ans += maxProfit;
        }
        return ans;
    }
private:
    struct Comparator {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b){
            return a.first < b.first;
        }
    }cmp;
};
