/*
*
* Tag: Math
* Time: O(1)
* Space:O(1)
*/
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        if((tomatoSlices&1) == 1 || tomatoSlices < 2*cheeseSlices || 4*cheeseSlices < tomatoSlices){
            return ans;
        }
        
        ans.resize(2);
        ans[0] = (tomatoSlices>>1) - cheeseSlices;
        ans[1] = 2*cheeseSlices - (tomatoSlices>>1);
        return ans;
    }
};
