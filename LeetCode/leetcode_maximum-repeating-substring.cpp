/*
*
* Tag: String
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if(sequence == word) {
            return 1;
        }
        if(sequence.size() < word.size()) {
            return 0;
        }
        
        int ans = 0, n = sequence.size(), m = word.size();
        for(int i = 0; i < n; ++ i) {
            if(sequence[i] != word[0]) {
                continue;
            }
            
            int cnt = 0, l = i;
            while(l < n) {
                bool isMatched = false;
                for(int j = 0; l < n && j < m; ++ j, ++ l) {
                    if(sequence[l] != word[j]) {
                        break;
                    }
                    if(j == m - 1) {
                        isMatched = true;
                    }
                }
                if(!isMatched) {
                    break;
                }
                ++ cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
