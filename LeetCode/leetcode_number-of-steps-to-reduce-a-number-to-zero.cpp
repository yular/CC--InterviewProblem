/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while(num > 0) {
            if((num&1) > 0) {
                ++ ans;
            }
            ++ ans;
            num >>= 1;
        }
        return ans - 1;
    }
};
