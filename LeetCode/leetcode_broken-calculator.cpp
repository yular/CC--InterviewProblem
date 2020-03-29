/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int brokenCalc(int x, int y) {
        if(x >= y) {
            return x - y;
        }
        
        int cnt = 0;
        while(y > x) {
            if((y&1) == 1) {
                ++ y;
            } else {
                y >>= 1;
            }
            ++ cnt;
        }
        cnt += (x - y);
        return cnt;
    }
};
