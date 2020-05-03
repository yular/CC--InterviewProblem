/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maxDiff(int num) {
        if(num <= 0) {
            return 0;
        }
        
        string s = to_string(num);
        string maxNum = s;
        for(int i = 0; i < s.size(); ++ i) {
            if(s[i] != '9') {
                convertNum(maxNum, '9', s[i], i);
                break;
            }
        }
        
        string minNum = s;
        if(s[0] != '1') {
            convertNum(minNum, '1', s[0], 0);
        } else {
            for(int i = 1; i < s.size(); ++ i) {
                if(s[i] != '0' && s[i] != s[0]) {
                    convertNum(minNum, '0', s[i], i);
                    break;
                }
            }
        }
        
        return stoi(maxNum) - stoi(minNum);
    }
private:
    void convertNum(string &s, char target, char origin, int startIdx) {
        for(int i = startIdx; i < s.size(); ++ i) {
            if(s[i] == origin) {
                s[i] = target;
            }
        }
        return ;
    }
};
