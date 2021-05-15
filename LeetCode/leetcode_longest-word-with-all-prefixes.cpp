/*
*
* Tag: Hash
* Time: O(m) total length of input string
* Space: O(n)
*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        if(words.size() == 0) {
            return "";
        }
        
        unordered_set<string> dict;
        for(string w : words) {
            dict.insert(w);
        }
        
        string ans = "";
        for(string w : words) {
            string tmp = "";
            bool isFind = true;
            for(int i = 0; i < w.size(); ++ i) {
                tmp += w[i];
                if(dict.count(tmp) == 0) {
                    isFind = false;
                    break;
                }
            }
            if(isFind) {
                if(w.size() > ans.size()) {
                    ans = w;
                } else if(w.size() == ans.size()) {
                    ans = min(ans, w);
                }
            }
        }
        return ans;
    }
};
