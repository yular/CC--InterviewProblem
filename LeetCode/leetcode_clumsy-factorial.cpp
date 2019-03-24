/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int clumsy(int N) {
        int ans = 0;
        bool isFirst = true;
        for(; N > 0; N -= 4){
            int v = N;
            if(N >= 3){
                v = N*(N - 1)/(N - 2);
            } 
            
            v *= -1;
            if(isFirst) {
                v *= -1;
                isFirst = false;
            }
            
            ans = ans + v + (N >= 4 ? N - 3 : 0);
        }
        return ans;
    }
};
