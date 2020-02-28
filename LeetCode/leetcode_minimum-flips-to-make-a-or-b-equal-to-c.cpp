/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a > 0 || b > 0 || c > 0) {
            int a_bit = a&1, b_bit = b&1, c_bit = c&1;
            a >>= 1, b >>= 1, c >>= 1;
            
            if((a_bit|b_bit) == c_bit) {
                continue;
            }
            
            if(c_bit == 0) {
                ans += (a_bit + b_bit);
            } else {
                ++ ans;
            }
        }
        return ans;
    }
};
