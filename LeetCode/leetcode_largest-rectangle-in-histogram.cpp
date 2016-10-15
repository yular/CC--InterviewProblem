/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0, idx = 0;
        stack<int> stk;
        height.push_back(0);
        for(int i = 0; i < height.size();){
            if(stk.empty() || height[stk.top()] < height[i])
                stk.push(i ++);
            else{
                idx = stk.top();
                stk.pop();
                res = max(res, height[idx]*(stk.empty()?i:(i - stk.top() - 1)));
            }
        }
        return res;
    }
};
