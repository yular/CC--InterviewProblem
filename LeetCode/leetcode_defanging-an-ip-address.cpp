/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(char ch : address) {
            if(ch == '.'){
                ans += "[.]";
                continue;
            }
            ans += ch;
        }
        return ans;
    }
};
