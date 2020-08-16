/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    int minOperations(int n) {
        return (n&1) > 0? (n>>1)*((n>>1) + 1) : (n>>1) + (n>>1)*((n>>1) - 1);
    }
};
