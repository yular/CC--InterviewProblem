/*
*
* Tag: Statistics
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        if(A.size() == 0 || B.size() == 0){
            return A;
        }
        
        vector<int> maxLetterCntOfB(26, 0);
        for(string word : B){
            vector<int> letterCnt(26, 0);
            for(char c : word){
                int idx = (c - 'a');
                ++ letterCnt[idx];
                
                maxLetterCntOfB[idx] = max(maxLetterCntOfB[idx], letterCnt[idx]);
            }
        }
        
        vector<string> ans;
        for(string word : A){
            vector<int> letterCnt(26, 0);
            for(char c : word){
                int idx = (c - 'a');
                ++ letterCnt[idx];
            }
            
            bool isUniversal = true;
            for(int i = 0; i < 26; ++ i){
                if(letterCnt[i] < maxLetterCntOfB[i]){
                    isUniversal = false;
                }
            }
            
            if(isUniversal){
                ans.push_back(word);
            }
        }
        return ans;
    }
};
