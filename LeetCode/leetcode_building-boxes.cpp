/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
* Credit: https://leetcode.com/problems/building-boxes/discuss/1032016/C%2B%2B-Python-3-variables-solution-with-drawing-explanation
*/

class Solution {
public:
    int minimumBoxes(int n) {
        if(n < 4) {
            return n;
        }
        
        long long sum = 0, ans = 0, i = 0;
        while(sum < n) {
            ++ i;
            ans += i;
            sum += ans;
        }
        if(sum == n) {
            return ans;
        }
        
        sum -= ans;
        ans -= i;
        i = 0;
        while(sum < n) {
            ++ i;
            sum += i;
        }
        ans += i;
        return ans;
    }
};
