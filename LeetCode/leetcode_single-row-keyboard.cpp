/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        if(word.size() == 0){
            return 0;
        }
        
        vector<int> pos(26, 0);
        for(int i = 0; i < keyboard.size(); ++ i){
            pos[keyboard[i] - 'a'] = i;
        }
        
        int ans = 0;
        int cur = 0;
        for(char w : word) {
            int nxt = pos[w - 'a'];
            ans += abs(nxt - cur);
            cur = nxt;
        }
        return ans;
    }
};
