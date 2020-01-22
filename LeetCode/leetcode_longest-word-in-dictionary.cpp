/*
*
* Tag: Hash
* Time: O(n*m) where m is the average the length of words. 
* Space: O(n)
*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        if(words.size() == 0){
            return ans;
        }
        
        unordered_set<string> dict(words.begin(), words.end());
        for(string word : words){
            if(isBuiltable(word, dict)){
                ans = word.size() > ans.size()? word : word.size() == ans.size()? word < ans? word : ans : ans;
            }
        }
        return ans;
    }
private:
    bool isBuiltable(string &word, unordered_set<string> &dict){
        string key = "";
        for(char w : word){
            key += w;
            if(dict.count(key) == 0) {
                return false;
            }
        }
        
        return true;
    }
};
