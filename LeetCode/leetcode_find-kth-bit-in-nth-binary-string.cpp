/*
*
* Tag: Implementation
* Time: O(2^n)
* Space: O(2^n)
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) {
            return '0';
        }
        
        string s = "0";
        for(int i = 2; i <= n; ++ i) {
            string tmp = s;
            s = s + '1' + processStr(tmp);
        }
        return s[k - 1];
    }
    
private:
    string processStr(string &s) {
        for(int l = 0, r = s.size() - 1; l <= r; swap(s[l], s[r]), ++ l, -- r) {
            if(s[l] == '0') {
                s[l] = '1';
            } else {
                s[l] = '0';
            }
            
            if(l == r) {
                continue;
            }
            
            if(s[r] == '0') {
                s[r] = '1';
            } else {
                s[r] = '0';
            }            
        }
        return s;
    }
};
