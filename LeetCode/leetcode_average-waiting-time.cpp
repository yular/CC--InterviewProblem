/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        if(customers.size() == 0) {
            return 0;
        }
        
        long long ans = 0, n = customers.size(), t = 0;
        for(int i = 0; i < n; ++ i) {
            if(t > customers[i][0]) {
                ans += (t - customers[i][0]);
            } else {
                t = customers[i][0];
            }
            ans += customers[i][1];
            t += customers[i][1];
        }
        return ans/(double)n;
    }
};
