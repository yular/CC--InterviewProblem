/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        if(costs.size() == 0) {
            return 0;
        }
        
        sort(costs.begin(), costs.end());
        int ans = 0, n = costs.size();
        for(int sum = 0, i = 0; i < n; ++ i, ++ ans) {
            sum += costs[i];
            if(sum > coins) {
                break;
            }
        }
        return ans;
    }
};
