/*
*
* Tag: String
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        if(sentence.size() == 0 || searchWord.size() == 0 ) {
            return -1;
        }
        
        vector<string> wds;
        string wd = "";
        for(int i = 0; i < sentence.size(); ++ i) {
            char c = sentence[i];
            wd += c;
            if(c == ' ' || i == sentence.size() - 1) {
                wds.push_back(wd);
                wd = "";
                continue;
            }
        }
        
        int ans = -1;
        for(int i = 0; i < wds.size(); ++ i) {
            if(isPrefix(searchWord, wds[i])) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
private:
    bool isPrefix(string s, string t) {
        if(s.size() > t.size()) {
            return false;
        }
        
        for(int i = 0; i < s.size(); ++ i) {
            if(s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
