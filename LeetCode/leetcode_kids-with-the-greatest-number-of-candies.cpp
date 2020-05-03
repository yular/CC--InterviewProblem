/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        if(candies.size() == 0) {
            return {};
        }
        
        int maxVal = candies[0];
        for(int i = 1; i < candies.size(); ++ i) {
            maxVal = max(maxVal, candies[i]);
        }
        
        vector<bool> ans(candies.size(), false);
        for(int i = 0; i < candies.size(); ++ i) {
            int c = candies[i];
            if(c + extraCandies >= maxVal) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
