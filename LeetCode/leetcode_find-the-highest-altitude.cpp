/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        if(gain.size() == 0) {
            return 0;
        }
        
        int ans = 0, sum = 0;
        for(int i = 0; i < gain.size(); ++ i) {
            sum += gain[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
