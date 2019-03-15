/*
*
* Tag: 
* Time: O(nlgn)
* Space: O()
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        
        int ans = 0, score = 0;
        for(int fwdIt = 0, bwdIt = tokens.size() - 1; fwdIt <= bwdIt;){
            if(P >= tokens[fwdIt]) {
                P -= tokens[fwdIt];
                ++ fwdIt;
                ++ score;
                ans = max(ans, score);
                continue;
            }
            
            if(score == 0){
                break;
            }
            
            -- score;
            P += tokens[bwdIt];
            -- bwdIt;
        }
        return ans;
    }
};
