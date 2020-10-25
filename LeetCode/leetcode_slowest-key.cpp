/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        if(releaseTimes.size() == 0 || releaseTimes.size() != keysPressed.size()) {
            return 0;
        }
        
        vector<int> timeCnt(26, 0);
        char ans = 0;
        int maxTime = 0;
        for(int i = 0; i < keysPressed.size(); ++ i) {
            int t = i == 0 ? releaseTimes[i] : releaseTimes[i] - releaseTimes[i - 1];
            timeCnt[keysPressed[i] - 'a'] = t;
            if(timeCnt[keysPressed[i] - 'a'] > maxTime) {
                maxTime = timeCnt[keysPressed[i] - 'a'];
                ans = keysPressed[i];
            } else if(timeCnt[keysPressed[i] - 'a'] == maxTime) {
                ans = max(ans, keysPressed[i]);
            }
        }
        return ans;
    }
};
