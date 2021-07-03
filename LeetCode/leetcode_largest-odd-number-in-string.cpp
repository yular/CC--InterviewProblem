/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string largestOddNumber(string num) {
        if(num.size() == 0) {
            return "";
        }
        
        int n = num.size();
        for(int i = n - 1; i >= 0; -- i) {
            int v = num[i] - '0';
            if(v%2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
