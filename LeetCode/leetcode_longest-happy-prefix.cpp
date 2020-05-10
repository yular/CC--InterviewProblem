/*
*
* Tag: Rolling Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    string longestPrefix(string s) {
        long long l = 0, r = 0, p = 1;
        int len = 0, n = s.size();
        for (int i = 0; i < n - 1; i++) {
            l = (l * 26 + (s[i] -'a')) % MOD;
            r = (r + p * (s[n - i - 1] - 'a')) % MOD;
            if (l == r) len = i + 1;
            p = p * 26 % MOD;
        }
        return s.substr(0, len);
    }
};
