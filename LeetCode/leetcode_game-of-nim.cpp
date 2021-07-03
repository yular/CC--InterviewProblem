/*
*
* Tag: Game Theory
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool nimGame(vector<int>& piles) {
        if(piles.size() == 0) {
            return false;
        }
        
        int v = 0;
        for(int p : piles) {
            v ^= p;
        }
        return v > 0;
    }
};
