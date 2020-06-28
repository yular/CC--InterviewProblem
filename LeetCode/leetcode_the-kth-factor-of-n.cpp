/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int kthFactor(int n, int k) {
        if(n < 1 || k > n) {
            return -1;
        }
        
        for(int i = 1, cnt = 0; i <= n; ++ i) {
            if(n%i != 0) {
                continue;
            }
            ++ cnt;
            if(cnt >= k) {
                return i;
            }
        }
        return -1;
    }
};
