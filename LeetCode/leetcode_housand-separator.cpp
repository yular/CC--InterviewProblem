/*
*
* Tag: string
* Time: O(m) m is the number of digits of given number n
* Space: O(1)
*/

class Solution {
public:
    string thousandSeparator(int n) {
        if(n < 1000) {
            return to_string(n);
        }
        
        string tmp = to_string(n);
        reverse(tmp.begin(), tmp.end());
        
        string ans = "";
        for(int i = 0; i < tmp.size(); ++ i) {
            if(i > 0 && i%3 == 0) {
                ans += '.';
            }
            ans += tmp[i];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
