/*
*
* Tag: Brainteaser
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(n == 0) {
            return 0;
        }
        
        int ans = 0;
        for(int l : left) {
            ans = max(ans, l);
        }
        for(int r : right) {
            ans = max(ans, n - r);
        }
        return ans;
    }
};
