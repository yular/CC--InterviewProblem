/*
*
* Tag: Stack 
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size() == 0) {
            return {};
        }
        
        vector<int> stk(asteroids.size());
        int top = 0;
        for(int i = 0; i < asteroids.size(); ++ i) {
            if(top == 0 || stk[top - 1] < 0 || asteroids[i] > 0) {
                stk[top ++] = asteroids[i];
                continue;
            }
            
            bool isExist = true;
            while(top > 0 && isExist) {
                if(stk[top - 1] < 0) {
                    break;
                }
                if(stk[top - 1] > abs(asteroids[i])) {
                    isExist = false;
                } else if(stk[top - 1] == abs(asteroids[i])) {
                    isExist = false;
                    -- top;
                } else {
                    -- top;
                }
            }
            if(isExist) {
                stk[top ++] = asteroids[i];
            }
        }
        
        vector<int> ans(top);
        for(int i = 0; i < top; ++ i) {
            ans[i] = stk[i];
        }
        return ans;
    }
};
