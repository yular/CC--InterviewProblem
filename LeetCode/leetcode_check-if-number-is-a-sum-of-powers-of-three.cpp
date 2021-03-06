/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n < 1) {
            return false;
        }
        if(n == 1) {
            return true;
        }
        while(n >= 3) {
            int v = n%3;
            if(v == 0) {
                n /= 3;
            } else if(v == 1) {
                n -= 1;
                n /= 3;
            } else {
                n = 2;
            }
        }
        return n == 1;
    }
};
