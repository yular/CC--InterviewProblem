/*
*
* Tag: Brute Force
* Time: O(n^3)
* Space: O(1)
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0, n = rating.size();
        for(int i = 0; i < n - 2; ++ i){
            for(int j = i + 1; j < n - 1; j ++) {
                for(int k = j + 1; k < n; ++ k) {
                    if((rating[i] > rating[j] && rating[j] > rating[k]) || (rating[i] < rating[j] && rating[j] < rating[k])) {
                        ++ ans;
                    }
                }
            }
        }
        return ans;
    }
};
