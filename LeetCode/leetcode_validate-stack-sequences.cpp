/*
*
* Tag: Stack (Data Structure)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }
        stack<int> stk;
        int indexOfPushed = 0, indexOfPopped = 0;
        for(; indexOfPushed < pushed.size(); ++ indexOfPushed){
            while(!stk.empty() && indexOfPopped < popped.size() && popped[indexOfPopped] == stk.top()){
                stk.pop();
                ++ indexOfPopped;
            }
            stk.push(pushed[indexOfPushed]);
        }
        while(!stk.empty() && indexOfPopped < popped.size() && popped[indexOfPopped] == stk.top()){
                stk.pop();
                ++ indexOfPopped;
        }
        
        return indexOfPopped >= popped.size();
    }
};
