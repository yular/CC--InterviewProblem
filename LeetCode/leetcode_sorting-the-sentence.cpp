/*
*
* Tag: string
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string sortSentence(string s) {
        if(s.size() == 0) {
            return s;
        }
        
        vector<string> str(10, "");
        for(int i = 0; i < s.size(); ++ i) {
            string tmp = "";
            int idx = 0;
            while(i < s.size() && s[i] != ' ') {
                if(s[i] >= '0' && s[i] <= '9') {
                    idx = s[i] - '0';
                } else {
                    tmp += s[i];
                }
                ++ i;
            }
            str[idx] = tmp;
        }
        
        string ans = "";
        for(int i = 1; i < 10; ++ i) {
            if(str[i] == "") {
                break;
            }
            if(i > 1) {
                ans += " ";
            }
            ans += str[i];
        }
        return ans;
    }
};
