/*
*
* Tag: Sliding Window
* Time: O(n)
* Space: O(1)
*

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, cnt = 0;
        for(int l = 0, r = 0; r < s.size(); ++ r) {
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                 ++ cnt;
            }
            
            if(r - l + 1 > k) {
                if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
                     -- cnt;
                }
                ++ l;
            }
            
            ans = max(ans, cnt);
        }
        return ans;
    }
};
