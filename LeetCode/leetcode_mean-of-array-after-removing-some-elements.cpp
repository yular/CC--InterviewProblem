/*
*
* Tag: Math
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    double trimMean(vector<int>& arr) {
        if(arr.size() == 0) {
            return 0;
        }
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size(), m = n/20, sum = 0, tot = 0;
        for(int i = m; i < n - m; ++ i, ++ tot) {
            sum += arr[i];
        }
        return (double)sum/(double)tot;
    }
};
