/*
*
* Tag: Game Theory, DP
* Time: O(n^1.5)
* Space: O(n)
*/

class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n <= 0) {
            return false;
        }
        
        vector<bool> sg(n + 1, false);
        sg[0] = false;
        for(int i = 1; i <= n; ++ i) {
            for(int j = 1; j*j <= i; ++ j) {
                int v = j*j;
                if(!sg[i - v]){
                    sg[i] = true;
                    break;
                }
            }
        }
        
        return sg[n];
    }
};
