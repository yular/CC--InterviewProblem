/*
*
* Tag: string (next permutation)
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string nextPalindrome(string num) {
        if(num.size() < 2) {
            return num;
        }
        
        int n = num.size(), len = n/2;
        string s = "";
        for(int i = 0; i < len; ++ i) {
            s += num[i];
        }
        
        int i = len - 2;
        while(i >= 0 && s[i] >= s[i + 1]) {
            -- i;
        }
        if(i < 0) {
            return "";
        }
        int j = len - 1;
        while(j >= 0 && s[i] >= s[j]) {
            -- j;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        
        string ans = s;
        if(n%2 == 1) {
            ans += num[n/2];
        }
        reverse(s.begin(), s.end());
        ans += s;
        return ans;
    }
};
