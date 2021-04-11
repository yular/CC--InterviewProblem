/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1) {
            return 1;
        }
        
        vector<int> arr(n, 0);
        for(int i = 0; i < n; ++ i) {
            arr[i] = i + 1;
        }
        
        int cur = 0;
        while(n > 1) {
            cur = (cur + k - 1 + n)%n;
            vector<int> tmp(n - 1);
            for(int i = 0, j = 0; i < n; ++ i) {
                if(i != cur) {
                    tmp[j ++] = arr[i];
                }
            }
            arr = tmp;
            -- n;
            if(cur >= n) {
                cur = 0;
            }
        }
        return arr[0];
    }
};
