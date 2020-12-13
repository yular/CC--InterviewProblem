/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minPartitions(string n) {
        if(n.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        for(char c : n) {
            ans = max(ans, c - '0');
            if(ans == 9) {
                break;
            }
        }
        return ans;
    }
};
