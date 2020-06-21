/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        if(n < 2) {
            return start;
        }
        
        int ans = start;
        for(int i = 1; i < n; ++ i) {
            ans ^= (start + 2*i);
        }
        return ans;
    }
};
