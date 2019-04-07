/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string maskPII(string S) {
        if(S.size() == 0){
            return S;
        }
        
        string ans = "";
        int pos = S.find("@");
        if(pos == -1) {
            int numOfVisDigits = 0;
            for(int i = S.size() - 1; i >= 0; -- i){
                char s = S[i];
                if(isdigit(s) == false) {
                    continue;
                }
                ans += numOfVisDigits >= 4 ? '*' : s;
                ++ numOfVisDigits;
                if(numOfVisDigits == 4 || numOfVisDigits == 7 || numOfVisDigits == 10) {
                    ans += "-";
                }
            }
            if(ans.back() == '-') {
                ans.pop_back();
            }
            if(numOfVisDigits > 10) {
                ans += "+";
            }
            reverse(ans.begin(), ans.end());
        } else {
            for(int i = 0; i < S.size(); ++ i){
                char s = S[i];
                if(isalpha(s)) {
                    s = tolower(s);
                }
                if(i == 0 || i >= pos) {
                    ans += s;
                } else if(i == pos - 1) {
                    ans += "*****";
                    ans += s;
                }
            }
        }
        return ans;
    }
};
