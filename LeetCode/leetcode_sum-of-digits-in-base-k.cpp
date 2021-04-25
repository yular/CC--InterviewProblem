/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int sumBase(int n, int k) {
        if(n == 0 || k < 2) {
            return 0;
        }
        
        int sum = 0;
        for(; n > 0; n /= k) {
            sum += n%k;
        }
        return sum;
    }
};
