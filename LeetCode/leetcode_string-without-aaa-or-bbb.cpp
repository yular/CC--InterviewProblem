/*
*
* Tag: Greedy
* Time: O(a + b)
* Space: O(1)
*/

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int arr[2] = {a, b};
        int idx = a >= b ? 0 : 1;
        
        string ans = "";
        while(arr[0] > 0 || arr[1] > 0) {
            if(arr[idx] >= arr[(idx + 1)%2]) {
                if(arr[idx] >= 2) {
                    ans += ('a' + idx);
                    -- arr[idx];
                }
            }
            ans += ('a' + idx);
            -- arr[idx];
            
            idx = (idx + 1)%2;
        }
        return ans;
    }
};
