/*
*
* Tag: Hash, Sliding Window
* Time: O((maxsize - minsize)*n)
* Space: O(maxsize*n)
*/

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        if(s.size() < minSize || maxSize == 0 || maxLetters == 0 || minSize > maxSize) {
            return 0;
        }
        
        string str = "";
        int ans = 0, len = 0;
        for(int k = minSize; k <= maxSize; ++ k) {
            unordered_map<string,int> wdCnt;
            vector<int> charCnt(26, 0);
            int cnt = 0;
            
            for(int l = 0, r = 0; r < s.size(); ++ r){
                ++ charCnt[s[r] - 'a'];
                if(charCnt[s[r] - 'a'] == 1) {
                    ++ cnt;
                }
                len = r - l + 1;
                if(len < k) {
                    continue;
                }
                
                if(cnt <= maxLetters) {
                    string str = s.substr(l, r - l + 1);
                    ++ wdCnt[str];
                    ans = max(ans, wdCnt[str]);
                }
                
                -- charCnt[s[l] - 'a'];
                if(charCnt[s[l] - 'a'] == 0) {
                    -- cnt;
                }
                ++ l;
            }
        }
        return ans;
    }
};
