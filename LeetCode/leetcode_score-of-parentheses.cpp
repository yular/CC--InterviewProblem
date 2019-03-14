/*
*
* Tag: Stack
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;
        if(S.size() == 0){
            return ans;
        }
        
        stack<char> parenthesestk;
        stack<int> pointstk;
        for(char s : S) {
            if(s == '(') {
                parenthesestk.push(s);
                pointstk.push(0);
                continue;
            }
            
            int sum = 0;
            while(!parenthesestk.empty() && !pointstk.empty()) {
                int val = pointstk.top();
                pointstk.pop();
                if(val == 0){
                    break;
                }
                
                sum += val;
            }
            parenthesestk.pop();
            sum <<= 1;
            if(sum == 0){
                ++ sum;
            }
            pointstk.push(sum);
        }
        
        while(!pointstk.empty()){
            ans += pointstk.top();
            pointstk.pop();
        }
        return ans;
    }
};
