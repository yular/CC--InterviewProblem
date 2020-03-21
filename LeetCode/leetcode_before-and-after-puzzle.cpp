/*
*
* Tag: brute force, implementation
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        if(phrases.size() < 2) {
            return {};
        }
        
        int n = phrases.size();
        vector<vector<string>> phrasevec(n);
        for(int i = 0; i < n; ++ i) {
            if(phrases[i] == "") {
                continue;
            }
            
            int m = phrases[i].size();
            string prefix = "";
            for(int j = 0; j < m && phrases[i][j] != ' '; ++ j){
                prefix += phrases[i][j];
            }
            
            string suffix = "";
            for(int j = m - 1; j >= 0 && phrases[i][j] != ' '; -- j){
                suffix += phrases[i][j];
            }
            reverse(suffix.begin(), suffix.end());
            
            phrasevec[i] = {phrases[i], prefix, suffix};
        }
        
        set<string> ans;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j) {
                if(i == j) {
                    continue;
                }
                
                if(phrasevec[i][2] == phrasevec[j][1]) {
                    string newPhrase = phrases[i];
                    if(phrasevec[j][1] != phrases[j]) {
                        int startIdx = phrasevec[j][1].size();
                        newPhrase += phrases[j].substr(startIdx);
                    }
                    
                    ans.insert(newPhrase);
                }
            }
        }
        
        vector<string> vecAns(ans.begin(), ans.end());
        return vecAns;
    }
};
