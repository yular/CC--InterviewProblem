/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n <= 2) {
            return 1;
        }
        
        int t[3] = {0, 1, 1};
        for(int i = 3; i <= n; ++ i) {
            int sum = t[0] + t[1] + t[2];
            t[0] = t[1], t[1] = t[2], t[2] = sum;
        }
        return t[2];
    }
};
