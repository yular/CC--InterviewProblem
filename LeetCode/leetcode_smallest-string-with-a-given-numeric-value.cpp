/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        if(n <= 0 || k <= 0 || k > 26*n) {
            return "";
        }
        
        string ans = "";
        for(int i = 0; i < n; ++ i) {
            int sum = 26*(n - 1 - i);
            for(int j = 1; j <= 26; ++ j) {
                if(j + sum >= k) {
                    ans += ('a' + (j - 1));
                    k -= j;
                    break;
                }
            }
        }
        return ans;
    }
};
