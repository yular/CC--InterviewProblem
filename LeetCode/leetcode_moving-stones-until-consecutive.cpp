/*
*
* Tag: Greedy
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        
        int d1 = arr[1] - arr[0] - 1, d2 = arr[2] - arr[1] - 1;
        vector<int> ans = {2, d1 + d2};
        if(d1 == 0 && d2 == 0) {
            ans[0] = 0;
        } else if(d1 <= 1 || d2 <= 1) {
            ans[0] = 1;
        }
        
        return ans;
    }
};
