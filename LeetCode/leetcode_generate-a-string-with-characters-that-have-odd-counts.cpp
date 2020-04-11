/*
*
* Tag: String
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string generateTheString(int n) {
        if(n == 1) {
            return "a";
        }
        
        string ans = "";
        if(n%2 == 0){
            ans += "a";
            -- n;
        }
        for(int i = 0; i < n; ++ i) {
            ans += "b";
        }
        return ans;
    }
};
