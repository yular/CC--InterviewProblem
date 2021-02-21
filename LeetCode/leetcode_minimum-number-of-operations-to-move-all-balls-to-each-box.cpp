/*
*
* Tag: Implementation
* Time: O(n^2) (can be O(n))
* Space: O(1)
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        if(boxes.size() == 0) {
            return {};
        }
        
        int n = boxes.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; ++ i) {
            ans[i] = calDis(boxes, i);
        }
        return ans;
    }
private:
    int calDis(string &boxes, int idx) {
        int dis = 0, n = boxes.size();
        for(int i = 0; i < n; ++ i) {
            if(boxes[i] == '1') {
                dis += abs(i - idx);
            }
        }
        return dis;
    }
};
