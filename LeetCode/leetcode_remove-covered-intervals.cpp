/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        
        int n = intervals.size(), ans = intervals.size();
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < n; ++ j) {
                if(i == j){
                    continue;
                }
                
                if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {
                    -- ans;
                    break;
                }
            }
        }
        return ans;
    }
};
