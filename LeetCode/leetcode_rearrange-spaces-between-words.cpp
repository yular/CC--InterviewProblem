/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string reorderSpaces(string text) {
        if(text.size() < 2) {
            return text;
        }
        
        string res = "", s = "";
        vector<string> arr;
        int cnt = 0;
        for(char c : text) {
            if(c == ' ') {
                ++ cnt;
                if(s.size() > 0) {
                    arr.push_back(s);
                    s = "";
                }
                continue;
            } else {
                s += c;
            }
        }
        if(s.size() > 0) {
            arr.push_back(s);
        }
        int emptyCnt = arr.size() <= 1? 0: cnt/(arr.size() - 1);
        for(int i = 0; i < arr.size(); ++ i){
            res += arr[i];
            if(i < arr.size() - 1) {
                res += string(emptyCnt, ' ');
                cnt -= emptyCnt;
            }
        }
        res += string(cnt, ' ');
        
        return res;
    }
};
