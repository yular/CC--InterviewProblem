/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int numSteps(string s) {        
        int ans = 0, c = 0;
        for(int i = s.size() - 1; i >= 0; -- i) {
            if(i == 0 && c == 0) {
                break;
            }
            
            int sum = c + (s[i] - '0');
            if(sum == 0) {
                ++ ans;
            } else if(sum == 1) {
                ans += 2;
                c = 1;
            } else {
                ++ ans;
                c = 1;
            }
        }
        return ans;
    }
};
