/*
*
* Tag: Game, DP
* Time: O(n^1.5)
* Space: O(n)
*/

class Solution {
public:
    bool divisorGame(int N) {
        if(N == 0){
            return false;
        }
        
        vector<bool> sg(N + 1, false);
        for(int i = 2; i <= N; ++ i){
            bool res = true;
            for(int j = 1; j*j <= i && j < i; ++ j){
                if(i%j == 0){
                    res &= sg[i - j]; 
                }
            }
            sg[i] = res ? false : true;
        }
        return sg[N];
    }
};
