/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minFlips(string target) {
        if(target.size() == 0) {
            return 0;
        }
        
        int ans = 0, cnt = 0;
        for(char c : target) {
            int v = c - '0';
            if((ans&1) != v){
                ++ ans;
            }
        }
        return ans;
    }
};
