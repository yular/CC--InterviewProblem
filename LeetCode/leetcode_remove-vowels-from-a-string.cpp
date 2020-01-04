/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string removeVowels(string S) {
        string ans = "";
        for(char s : S){
            if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
                continue;
            }
            ans += s;
        }
        return ans;
    }
};
