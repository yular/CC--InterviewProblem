/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() < 2) {
            return "";
        }
        
        string ans = palindrome;
        int len = palindrome.size()/2;
        for(int i = 0; i < len; ++ i){
            if(palindrome[i] != 'a') {
                ans[i] = 'a';
                break;
            }
            if(i == len - 1){
                ans[ans.size() - 1] = 'b';
            }
        }
        return ans;
    }
};
