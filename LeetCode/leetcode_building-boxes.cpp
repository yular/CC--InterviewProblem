/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minimumBoxes(int n) {
        if(n < 4) {
            return n;
        }
        
        long long sum = 0, ans = 0, i = 0;
        while(sum < n) {
            ++ i;
            ans += i;
            sum += ans;
        }
        if(sum == n) {
            return ans;
        }
        
        sum -= ans;
        ans -= i;
        i = 0;
        while(sum < n) {
            ++ i;
            sum += i;
        }
        ans += i;
        return ans;
    }
};
