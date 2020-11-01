/*
*
* Tag: Hash
* Time: O(m^2 + n^3)
* Space: O(m^2)
*/

class Solution {
public:
    int countSubstrings(string s, string t) {
        if(t.size() == 0) {
            return 0;
        }
        
        unordered_map<string, int> dict;
        for(int i = 0; i < t.size(); ++ i) {
            string str = "";
            for(int j = i; j < t.size(); ++ j) {
                str += t[j];
                ++ dict[str];
            }
        }
        
        int ans = 0;
        for(int i = 0; i < s.size(); ++ i) {
            string str = "";
            for(int j = i; j < s.size(); ++ j) {
                str += s[j];
                ans += countValidSubstr(str, dict);
            }
        }
        return ans;
    }
    
private:
    int countValidSubstr(string &str, unordered_map<string, int> &dict) {
        int cnt = 0;
        string tmp = str;
        for(int i = 0; i < str.size(); ++ i) {
            char origin = str[i];
            for(char j = 'a'; j <= 'z'; ++ j) {
                if(j == origin) {
                    continue;
                }
                
                str[i] = j;
                if(dict.count(str)) {
                    cnt += dict[str];
                }
            }
            str[i] = origin;
        }
        return cnt;
    }
};
