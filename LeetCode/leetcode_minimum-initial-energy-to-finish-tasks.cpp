/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        if(tasks.size() == 0) {
            return 0;
        }
        
        sort(tasks.begin(), tasks.end(), cmp);
        
        int n = tasks.size(), ans = 0;
        for(int i = 0; i < n; ++ i) {
            ans = max(ans + tasks[i][0], tasks[i][1]);
        }
        return ans;
    }
    
private:
    struct comparator{
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[1] - a[0] < b[1] - b[0];
        }
    }cmp;
};
