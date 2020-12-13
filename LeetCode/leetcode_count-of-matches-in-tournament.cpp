/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int numberOfMatches(int n) {
        if(n < 2) {
            return 0;
        }
        
        int ans = 0;
        for(; n > 1;) {
            ans += (n>>1);
            if((n&1) == 1) {
                n = (n>>1) + 1;
            } else {
                n >>= 1;
            }
        }
        return ans;
    }
};
