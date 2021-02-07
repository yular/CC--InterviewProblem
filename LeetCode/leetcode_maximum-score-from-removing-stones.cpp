/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> arr = {a, b, c};
        int cnt = 0;
        for(int i = 0; i < 3; ++ i) {
            if(arr[i] == 0) {
                ++ cnt;
            }
        }
        
        int ans = 0;
        for(; cnt < 2; ) {
            sort(arr.begin(), arr.end());
            if(arr[0] == 0 && arr[1] == 0) {
                break;
            }
            
            -- arr[2], -- arr[1];
            ++ ans;
        }
        return ans;
    }
};
