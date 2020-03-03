/*
*
* Tag: Array
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        vector<int> customerSatisfication(n, 0), allSatification(n, 0);
        for(int i = n - 1; i >= 0; -- i){
            if(i == n - 1) {
                allSatification[i] = customers[i];
                customerSatisfication[i] =  grumpy[i] == 0? customers[i] : 0;
                continue;
            }
            allSatification[i] = allSatification[i + 1] + customers[i];
            customerSatisfication[i] = (grumpy[i] == 0? customers[i] : 0) + customerSatisfication[i + 1];
        }
        
        
        if(X == 0) {
            return customerSatisfication[0];
        }
        if(X == n) {
            return allSatification[0];
        }
        
        int ans = 0, curSatisFication = 0;
        for(int i = 0; i + X <= n; ++ i){
            if(i + X == n){
                ans = max(ans, curSatisFication + allSatification[i]);
                continue;
            }
            ans = max(ans, curSatisFication + allSatification[i] - allSatification[i + X] + customerSatisfication[i + X]);
            curSatisFication += (grumpy[i] == 0? customers[i] : 0);
        }
        return ans;
    }
};
