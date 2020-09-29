/*
*
* Tag: Greedy
* Time: O(nm)
* Space: O(1)
*/

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if(customers.size() == 0) {
            return -1;
        }
        
        int tot = 0;
        for(int customer : customers) {
            tot += customer;
        }
        if(tot == 0) {
            return -1;
        }
        
        int ans = 0, pendingCnt = 0, cur = 0, idx = 0, cnt = 0, tmpcnt = 0;
        for(; tot > 0; ) {
            if(ans < cur) {
                ans = cur;
                cnt = tmpcnt;
            }
            
            if(idx < customers.size()) {
                pendingCnt += customers[idx++];
            }
            
            int v = 4;
            if(pendingCnt < 4) {
                v = pendingCnt;
            }
            cur += boardingCost*v;
            tot -= v;
            if(pendingCnt >= v) {
                pendingCnt -= v;
            }

            cur -= runningCost;
            ++ tmpcnt;
            if(ans < cur) {
                ans = cur;
                cnt = tmpcnt;
            }
        }
        return ans <= 0? -1 : cnt;
    }
};
