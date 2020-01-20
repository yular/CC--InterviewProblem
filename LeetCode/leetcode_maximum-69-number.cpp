/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int maximum69Number (int num) {
        string s_num = to_string(num);
        for(int i = 0; i < s_num[i]; ++ i){
            if(s_num[i] == '6'){
                s_num[i] = '9';
                break;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < s_num[i]; ++ i){
            ans = (ans*10) + (s_num[i] - '0');
        }
        return ans;
    }
};
