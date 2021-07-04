/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        if(dist.size() != speed.size()) {
            return 0;
        }
        
        int n = dist.size();
        vector<double> t(n, 0);
        for(int i = 0; i < n; ++ i) {
            t[i] = (double)dist[i]/(double)speed[i];
        }
        
        sort(t.begin(), t.end());
        
        int ans = 1;
        for(int i = 1; i < n && (double)i < t[i]; ++ i, ++ ans) ;
        return ans;
    }
};
