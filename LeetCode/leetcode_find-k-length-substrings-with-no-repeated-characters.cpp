/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int ans = 0;
        if(S.size() < K || K > 26) {
            return ans;
        }
        
        vector<int> charCnt(26, false);
        int numOfDup = 0;
        for(int i = 0; i < S.size(); i ++) {
            if(i >= K){
                -- charCnt[S[i - K] - 'a'];
                if(charCnt[S[i - K] - 'a'] == 1) {
                    -- numOfDup;
                }
            }
            ++ charCnt[S[i] - 'a'];
            if(charCnt[S[i] - 'a'] == 2){
                ++ numOfDup;
            }
            if(i >= K - 1 && numOfDup == 0) {
                ++ ans;
            }
        }
        return ans;
    }
};
