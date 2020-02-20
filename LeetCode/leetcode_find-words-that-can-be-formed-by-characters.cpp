/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCnt(26, 0);
        getCharCnt(chars, charCnt);
        
        int ans = 0;
        for(string word : words){
            vector<int> wordCnt(26, 0);
            getCharCnt(word, wordCnt);
            if(canFormWord(charCnt, wordCnt)) {
                ans += word.size();
            }
        }
        return ans;
    }
private:
    void getCharCnt(string w, vector<int> &charCnt){
        for(char c : w){
            ++ charCnt[c - 'a'];
        }
        return ;
    }
    
    bool canFormWord(vector<int> &charCnt, vector<int> &wordCnt) {
        for(int i = 0; i < wordCnt.size(); ++ i){
            if(charCnt[i] < wordCnt[i]) {
                return false;
            }
        }
        return true;
    }
};
