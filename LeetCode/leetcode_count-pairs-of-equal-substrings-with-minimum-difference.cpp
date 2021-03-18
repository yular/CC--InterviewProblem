/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int countQuadruples(string firstString, string secondString) {
        if(firstString == "" || secondString == "") {
            return 0;
        }
        
        vector<vector<int>> firstPosDict(26, {INT_MAX, INT_MIN}), secondPosDict(26, {INT_MAX, INT_MIN});
        fillInPosDict(firstString, firstPosDict);
        fillInPosDict(secondString, secondPosDict);
        
        int ans = 0, minDist = INT_MAX;
        for(int i = 0; i < 26; ++ i) {
            if(firstPosDict[i][0] == INT_MAX || secondPosDict[i][0] == INT_MAX) {
                continue;
            }
            int dist = firstPosDict[i][0] - secondPosDict[i][1];
            if(dist < minDist) {
                ans = 1;
                minDist = dist;
            } else if(dist == minDist) {
                ++ ans;
            }
        }
        return ans;
    }
    
private:
    void fillInPosDict(string &str, vector<vector<int>> &posDict) {
        for(int i = 0; i < str.size(); ++ i) {
            int idx = str[i] - 'a';
            posDict[idx][0] = min(posDict[idx][0], i);
            posDict[idx][1] = max(posDict[idx][1], i);
        }
        return ;
    }
};
