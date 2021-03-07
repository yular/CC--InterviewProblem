/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size() == 0) {
            return false;
        }
        
        int cnt = 1;
        for(int i = 1; i < s.size(); ++ i){
            if(s[i]=='1' && s[i - 1] =='1'){
                cnt = 1;
            } else if(s[i]=='1' && cnt >= 1) {
                return false;
            }
        }
        return true;
    }
};
