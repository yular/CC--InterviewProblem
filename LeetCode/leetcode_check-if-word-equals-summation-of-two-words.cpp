/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int i = 0, j = 0, k = 0, c = 0, n = firstWord.size(), m = secondWord.size(), nn = targetWord.size();
        for(i = n - 1, j = m - 1, k = nn - 1; i >= 0 && j >= 0 && k >= 0; -- i, -- j, -- k){
            int a = firstWord[i] - 'a', b = secondWord[j] - 'a', s = targetWord[k] - 'a';
            int v = (a + b + c);
            if(v%10 != s) {
                cout<<a<<" "<<b<<" "<<c<<" "<<s<<endl;
                return false;
            }
            c = v/10;
        }
        while(i >= 0 && k >= 0) {
            int a = firstWord[i] - 'a', s = targetWord[k] - 'a';
            int v = (a + c);
            if(v%10 != s) {
                return false;
            }
            c = v/10;
            -- i, -- k;
        }
        while(j >= 0 && k >= 0) {
            int b = secondWord[j] - 'a', s = targetWord[k] - 'a';
            int v = (b + c);
            if(v%10 != s) {
                return false;
            }
            c = v/10;
            -- j, -- k;
        }
        if(c > 0) {
            if(k != 0) {
                return false;
            }
            if(targetWord[k] == 'b') {
                return true;
            }
            return false;
        }
        return true;
    }
};
