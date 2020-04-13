/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); ++ i) {
            if(i + 2 < s.size() && s[i + 2] == '#') {
                string v = ""; v += s[i]; v += s[i + 1];
                ans += getCharOf(v);
                i += 2;
                continue;
            }
            
            ans += (char)(s[i] - '0' - 1 + 'a');
        }
        
        return ans;
    }
private:
    char getCharOf(string v) {
        int res = stoi(v) - 1;
        return res + 'a';
    }
};
