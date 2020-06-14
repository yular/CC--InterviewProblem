/*
*
* Tag: Binary Search
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < m*k || n == 0) {
            return -1;
        }
        
        long long l = bloomDay[0], r = bloomDay[0];
        for(int d : bloomDay) {
            l = min(l, (long long)d);
            r = max(r, (long long)d);
        }
        
        int ans = 1;
        while(l <= r) {
            long long mid = (l + r)>>1;
            if(canMakeBouquets(bloomDay, mid, m, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
private:
    bool canMakeBouquets(vector<int>& bloomDay, long long wait, int m, int k) {
        int cntM = 0, cntK = 0;
        for(int d :  bloomDay) {
            if(d <= wait) {
                ++ cntK;
            } else {
                cntK = 0;
            }
            
            if(cntK >= k) {
                cntK = 0;
                ++ cntM;
            }
            
            if(cntM >= m) {
                return true;
            }
        }
        return false;
    }
};
