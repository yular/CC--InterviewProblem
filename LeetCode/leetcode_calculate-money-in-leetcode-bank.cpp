/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int totalMoney(int n) {
        if(n == 0) {
            return 0;
        }
        
        int sum = 0, start = 1;
        for(; n >= 7; n -= 7, start ++) {
            sum += (2*start + 6)*7/2;
        }
        sum += (2*start + n - 1)*n/2;
        return sum;
    }
};
