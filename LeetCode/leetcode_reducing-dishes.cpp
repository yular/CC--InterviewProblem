/*
*
* Tag: DP
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        if(satisfaction.size() == 0) {
            return 0;
        }
        
        sort(satisfaction.begin(), satisfaction.end());
        if(satisfaction[satisfaction.size() - 1] <= 0) {
            return 0;
        } 
        
        int ans = 0, totSum = 0, curSum = 0;
        for(int i = satisfaction.size() - 1; i >= 0; -- i) {
            curSum += satisfaction[i];
            ans = max(ans, curSum + totSum);
            totSum += curSum;
        }
        return ans;
    }
};
