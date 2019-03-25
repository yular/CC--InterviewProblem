/*
*
* Tag: Binary Search
* Time: O(n + lgm) where m is the sum of all array integers
* Space: O(1)
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int ans = 0;
        if(weights.size() == 0){
            return ans;
        }
        
        int sum = 0;
        for(int weight : weights){
            sum += weight;
        }
        
        int left = 1, right = sum;
        ans = INT_MAX;
        while(left <= right) {
            int mid = (left + right)>>1;
            if(canShipAllCargos(mid, weights, D)) {
                ans = min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
private:
    bool canShipAllCargos(int cap, vector<int>& weights, int d){
        int numOfDays = 0, curWeight = 0;
        for(int weight : weights) {
            if(weight > cap) {
                return false;
            }
            
            curWeight += weight;
            if(curWeight == cap) {
                ++ numOfDays;
                curWeight = 0;
            } else if(curWeight > cap) {
                ++ numOfDays;
                curWeight = weight;
            }
        }
        
        if(curWeight < cap && curWeight != 0) {
            ++ numOfDays;
        }
        return numOfDays <= d;
    }
};
