/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, product = 1;
        while(n > 0) {
            int v = n%10;
            n /= 10;
            sum += v;
            product *= v;
        }
        return product - sum;
    }
};
