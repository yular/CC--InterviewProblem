/*
*
* Tag: Greedy + Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        if(coins.size() == 0) {
            return 0;
        }
        
        sort(coins.begin(), coins.end());
        
        int ans = 0;
        for (int i = 0; i < coins.size() && coins[i] <= ans+1; ++i)
            ans += coins[i];
        return ans+1;
    }
};
