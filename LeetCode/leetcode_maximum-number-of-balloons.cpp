/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.size() == 0){
            return 0;
        }
        
        unordered_map<char, int> charCntBase = {{'b', 1}, {'a', 1}, {'l', 2}, {'o', 2}, {'n', 1}}, charCnt = {{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        for(char c : text) {
            if(c != 'b' && c != 'a' && c != 'l' && c != 'o' && c != 'n') {
                continue;
            }
            
            ++ charCnt[c];
        }
        
        int ans = text.size();
        for(auto it : charCnt) {
            if(it.second < charCntBase[it.first]) {
                return 0;
            }
            
            ans = min(ans, it.second / charCntBase[it.first]);
        }
        return ans;
    }
};
