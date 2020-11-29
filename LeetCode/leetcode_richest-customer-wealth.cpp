/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(vector<int> account : accounts) {
            int sum = 0;
            for(int v : account) {
                sum += v;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
