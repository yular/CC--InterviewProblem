/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if(words.size() == 0){
            return 0;
        }
        
        sort(words.begin(), words.end(), cmp);
        
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i = 1; i < n; ++ i){
            for(int j = i - 1; j >= 0; -- j) {
                if(words[i].size() == words[j].size()) {
                    continue;
                }
                
                if(words[i].size() - words[j].size() > 1) {
                    break;
                }
                
                if(isPredec(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
private:
    bool isPredec(string &a, string &b) {
        int numOfDiff = 0;
        for(int i = 0, j = 0; i < a.size() && j < b.size(); ++ j) {
            if(a[i] == b[j]) {
                ++ i;
                continue;
            }
            ++ numOfDiff;
        }
        return numOfDiff <= 1;
    }
    
    struct comparator {
        bool operator () (const string &a, const string &b) {
            return a.size() < b.size();
        }
    }cmp;
};
