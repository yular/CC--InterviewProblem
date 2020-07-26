/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    int countOdds(int low, int high) {
        int len = high - low, ans;
        ans = len/2;
        if(len&1 == 1) {
            if((low&1) == 0) {
                ++ ans;
            }
        }
        if((low&1) == 1) {
            ++ ans;
        }
        
        return ans;
    }
};
