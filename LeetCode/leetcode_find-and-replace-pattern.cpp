/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string word : words){
            if(word.size() != pattern.size()){
                continue;
            }
            
            unordered_map<char,char> patternToWord, wordToPattern;
            bool isValid = true;
            for(int i = 0; i < pattern.size(); ++ i){
                if(patternToWord.count(pattern[i]) != 0 && patternToWord[pattern[i]] != word[i]) {
                    isValid = false;
                    break;
                }
                if(wordToPattern.count(word[i]) != 0 && wordToPattern[word[i]] != pattern[i]) {
                    isValid = false;
                    break;
                }
                
                patternToWord[pattern[i]] = word[i];
                wordToPattern[word[i]] = pattern[i];
            }
            
            if(isValid){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
