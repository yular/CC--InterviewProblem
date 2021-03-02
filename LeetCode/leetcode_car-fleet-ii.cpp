/*
*
* Tag: Data Structure - Stack
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        if(cars.size() == 0) {
            return {};
        }
        
        int n = cars.size(), top = 0;
        vector<double> ans(n, -1);
        vector<int> stk(n, -1);
        stk[top ++] = n - 1;
        for(int i = n - 2; i >= 0; -- i) {
            while(top > 0) {
                int curIdx = stk[top - 1];
                if(cars[i][1] <= cars[curIdx][1]) {
                    if(ans[curIdx] < 0) {
                        stk[top ++] = i;
                        break;
                    }
                    -- top;
                    continue;
                }
                // calculate collide time
                double t = (double)(cars[curIdx][0] - cars[i][0])/(cars[i][1] - cars[curIdx][1]);
                if(curIdx == n - 1) {
                    ans[i] = t;
                    stk[top ++] = i;
                    break;
                }
                if(t <= ans[curIdx] || ans[curIdx] < 0) {
                    ans[i] = t;
                    stk[top ++] = i;
                    break;
                } else {
                    -- top;
                }
            }
        }
        
        return ans;
    }
};
