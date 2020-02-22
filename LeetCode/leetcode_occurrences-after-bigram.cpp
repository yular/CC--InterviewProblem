/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        if(text.size() < first.size() || text.size() < second.size()) {
            return ans;
        }
        
        vector<string> wdlist = getListOfWords(text);
        for(int i = 0; i < wdlist.size() - 2; ++ i){
            if(wdlist[i] == first && wdlist[i + 1] == second) {
                ans.push_back(wdlist[i + 2]);
            }
        }
        return ans;
    }
private:
    vector<string> getListOfWords(string text) {
        vector<string> ans;
        
        string w = "";
        for(int i = 0; i < text.size(); ++ i) {
            if(text[i] == ' ' || i == text.size() - 1) {
                if(text[i] != ' ') {
                    w += text[i];
                }
                ans.push_back(w);
                w = "";
                continue;
            }
            w += text[i];
        }
        return ans;
    }
};
