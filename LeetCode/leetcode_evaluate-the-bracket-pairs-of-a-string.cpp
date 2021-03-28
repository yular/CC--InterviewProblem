/*
*
* Tag: Hash
* Time: O(n)
* Space: O(m)
*/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        if(s.size() < 3) {
            return s;
        }
        
        unordered_map<string,string> dict;
        for(vector<string> k : knowledge) {
            dict[k[0]] = k[1];
        }
        
        string ans = "";
        for(int i = 0; i < s.size(); ++ i) {
            if(s[i] != '(') {
                ans += s[i];
                continue;
            }
            string key = "";
            ++ i;
            while(i < s.size() && s[i] != ')') {
                key += s[i ++];
            }
            if(dict.count(key) > 0) {
                ans += dict[key];
            } else {
                ans += "?";
            }
        }
        return ans;
    }
};
