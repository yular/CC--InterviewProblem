/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int countVowelStrings(int n) {
        if(n == 1) {
            return 5;
        }
        
        vector<int> cur(5, 1), prev(5, 1);
        for(int i = 2; i <= n; ++ i) {
            int sum = prev[4];
            for(int j = 3; j >= 0; -- j) {
                cur[j] = prev[j] + sum;
                sum += prev[j];
            }
            prev = cur;
        }
        
        int ans = 0;
        for(int i = 0; i < 5; ++ i) {
            ans += cur[i];
        }
        return ans;
    }
};
