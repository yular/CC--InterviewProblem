/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ans = 0;
        if(words.size() == 0){
            return ans;
        }
        
        vector<int> charCnt(26, 0);
        for(char letter : letters){
            ++ charCnt[letter - 'a'];
        }
        
        vector<pair<string,int>> validWords;
        for(string word : words){
            int res = getWordScore(word, charCnt, score);
            if(res > 0) {
                validWords.push_back(make_pair(word, res));
            }
        }
        
        dfs(validWords, 0, ans, 0, charCnt);
        return ans;
    }
    
private:
    int getWordScore(string word, vector<int> &charCnt, vector<int>& score){
        vector<int> curCharCnt(26, 0);
        for(char ch : word){
            ++ curCharCnt[ch - 'a'];
        }
        
        int res = 0;
        for(int i = 0; i < 26; ++ i){
            if(curCharCnt[i] > charCnt[i]) {
                return -1;
            }
            res += curCharCnt[i]*score[i];
        }
        return res;
    }
    
    void dfs(vector<pair<string,int>> validWords, int idx, int &ans, int sum, vector<int> &charCnt) {
        if(idx >= validWords.size()){
            return ;
        }
        
        string word = validWords[idx].first;
        vector<int> curCharCnt(26, 0);
        for(char ch : word){
            ++ curCharCnt[ch - 'a'];
        }
        
        bool isValid = true;
        for(int i = 0; i < 26; ++ i){
            if(curCharCnt[i] > charCnt[i]) {
                isValid = false;
                break;
            }
        }
        
        if(isValid) {
            sum += validWords[idx].second;
            for(int i = 0; i < 26; ++ i){
                charCnt[i] -= curCharCnt[i];
            }
        }
        ans = max(ans, sum);
        
        dfs(validWords, idx + 1, ans, sum, charCnt);
        
        if(isValid) {
            sum -= validWords[idx].second;
            for(int i = 0; i < 26; ++ i){
                charCnt[i] += curCharCnt[i];
            }
            dfs(validWords, idx + 1, ans, sum, charCnt);
        }
        return ;
    }
};
