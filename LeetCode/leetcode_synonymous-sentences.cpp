/*
*
* Tag: DFS
* Time: O(m) + O(k^n) + O(mlgm) m is the length of text, k is the number of words of text, and n is the average number of synonyms of each word.
* Space: O(n*m)
*/

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<string> ans;
        if(text.size() == 0){
            return ans;
        }
        
        unordered_map<string, vector<string>> dict;
        for(vector<string> syn : synonyms) {
            dict[syn[0]].push_back(syn[1]);
            dict[syn[1]].push_back(syn[0]);
        }
        
        vector<vector<string>> wordList;
        string cur = "";
        int idx = 0;
        for(int i = 0; i < text.size(); ++ i) {
            if(text[i] == ' ' || i == text.size() - 1){
                if(i == text.size() - 1) {
                    cur += text[i];
                }
                
                vector<string> synList = {cur};
                unordered_set<string> vis = {cur};
                fillAllSynoyms(dict, cur, synList, vis);
                wordList.push_back(synList);
                
                cur = "";
                continue;
            }
            
            cur += text[i];
        }
        
        cur = "";
        dfs(cur, ans, wordList, 0);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    void fillAllSynoyms(unordered_map<string, vector<string>> &dict, string cur, vector<string> &synList, unordered_set<string> &vis) {
        for(string wd : dict[cur]) {
            if(vis.count(wd) > 0) {
                continue;
            }
            vis.insert(wd);
            synList.push_back(wd);
            fillAllSynoyms(dict, wd, synList, vis);
        }
        
        return;
    }
    
    void dfs(string cur, vector<string> &ans, vector<vector<string>> &wordList, int idx) {
        if(idx >= wordList.size()) {
            ans.push_back(cur);
            return ;
        }
        
        for(string wd : wordList[idx]) {
            string nxt = idx == 0? wd : cur + " " + wd;
            dfs(nxt, ans, wordList, idx + 1);
        }
        return ;
    }
};
