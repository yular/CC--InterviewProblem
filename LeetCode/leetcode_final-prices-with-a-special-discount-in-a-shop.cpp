/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        for(int i = 0; i < ans.size() - 1; ++ i) {
            int discount = 0;
            for(int j = i + 1; j < ans.size(); ++ j) {
                if(prices[j] <= prices[i]) {
                    discount = prices[j];
                    break;
                }
            }
            ans[i] -= discount;
        }
        return ans;
    }
};
