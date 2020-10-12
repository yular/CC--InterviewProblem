/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        if(a == "") {
            return true;
        }
        if(a.size() != b.size()) {
            return false;
        }
        
        if(isPalindrome(a) || isPalindrome(b)) {
            return true;
        }
        
        return canFormPalindrome(a, b) || canFormPalindrome(b, a);
    }
    
private:
    bool isPalindrome(string &s) {
        for(int i = 0, j = s.size() - 1; i <= j; ++i, -- j) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool canFormPalindrome(string &s, string &t) {
        int i = 0, j = t.size() - 1;
        for(; i < s.size(); ++ i, -- j) {
            if(s[i] != t[j]) {
                break;
            }
        }
        if(i >= j) {
            return true;
        }
        if(i == 0) {
            return false;
        }
        
        bool isFound = true;
        for(int l = i, r = j; l <= r; ++ l, -- r) {
            if(t[l] != t[r]) {
                isFound = false;
                break;
            }
        }
        if(isFound) {
            return true;
        }
        
        for(int l = i, r = j; l <= r; ++ l, -- r) {
            if(s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
};
