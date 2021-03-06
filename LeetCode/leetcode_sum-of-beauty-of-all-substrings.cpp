/*
*
* Tag: String + Brute Force
* Time: O(n^2)
* Space: O(1)
*/

class Solution {
public:
    int beautySum(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        int n = s.size(), ans = 0;
        for(int i = 0; i < n - 1; ++ i) {
            vector<int> charCnt(26, 0);
            charCnt[s[i] - 'a'] = 1;
            for(int j = i + 1; j < n; ++ j) {
                ++ charCnt[s[j] - 'a'];
                int maxVal = 0, minVal = n;
                for(int k = 0; k < 26; ++ k) {
                    if(charCnt[k] == 0) {
                        continue;
                    }
                    maxVal = max(maxVal, charCnt[k]);
                    minVal = min(minVal, charCnt[k]);
                }
                //cout<<i<<" "<<j<<": "<<maxVal - minVal<<endl;
                ans += (maxVal - minVal);
            }
        }
        return ans;
    }
};
