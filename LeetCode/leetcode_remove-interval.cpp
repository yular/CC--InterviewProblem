/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        if(intervals.size() == 0 || toBeRemoved.size() == 0){
            return ans;
        }
        
        for(vector<int> interval : intervals){
            if(interval[0] >= toBeRemoved[0] && interval[0] <= toBeRemoved[1] && interval[1] >= toBeRemoved[0] && interval[1] <= toBeRemoved[1]) {
                continue;
            }
            if(interval[1] <= toBeRemoved[0] || interval[0] >= toBeRemoved[1]) {
                ans.push_back(interval);
                continue;
            }
            if(interval[0] <= toBeRemoved[0] && interval[1] >= toBeRemoved[0] && interval[1] <= toBeRemoved[1]) {
                ans.push_back({interval[0], toBeRemoved[0]});
                continue;
            }
            if(interval[0] <= toBeRemoved[1] && interval[0] >= toBeRemoved[0] && interval[1] >= toBeRemoved[1]) {
                ans.push_back({toBeRemoved[1], interval[1]});
                continue;
            }
            ans.push_back({interval[0], toBeRemoved[0]});
            ans.push_back({toBeRemoved[1], interval[1]});
        }
        return ans;
    }
};
