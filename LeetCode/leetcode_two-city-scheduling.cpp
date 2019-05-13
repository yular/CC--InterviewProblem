/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp);
        int numOfCityAPeople = 0, numOfCityBPeople = 0, n = costs.size()/2;
        int ans = 0;
        for(vector<int> cost : costs){
            if(numOfCityAPeople < n && numOfCityBPeople < n) {
                ans += min(cost[0], cost[1]);
                if(cost[0] < cost[1]) {
                    ++ numOfCityAPeople;
                } else {
                    ++ numOfCityBPeople;
                }
            } else if(numOfCityAPeople < n){
                ans += cost[0];
                ++ numOfCityAPeople;
            } else {
                ans += cost[1];
                ++ numOfCityBPeople;
            }
        }
        
        return ans;
    }
    
private:
    struct numberComparator{
        bool operator() (vector<int> a, vector<int> b){
            return abs(b[0] - b[1]) < abs(a[0] - a[1]);
        }
    }cmp;
};
