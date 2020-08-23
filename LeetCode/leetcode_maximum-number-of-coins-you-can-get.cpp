/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        if(piles.size() < 3 || piles.size()%3 != 0 ) {
            return 0;
        }
        
        sort(piles.begin(), piles.end());
        
        int ans = 0, n = piles.size()/3;
        for(int i = 0, j = piles.size() - 1; i < n; ++ i, j -= 2){
            ans += piles[j - 1];
        }
        return ans;
    }
};
