/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        if(n == 0) {
            return 0;
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            if(startTime[i] <= queryTime) {
                ++ ans;
            }
            if(endTime[i] + 1 <= queryTime) {
                -- ans;
            }
        }

        return ans;
    }
};
