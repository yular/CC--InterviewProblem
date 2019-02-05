/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int ans = 0;
        if(tree.size() == 0){
            return ans;
        }
        
        vector<int> basket(tree.size(), 0);
        int numOfFruit = 0, numOfFruitKind = 0;
        for(int i = 0, j = 0; i < tree.size(); ++ i){
            ++ basket[tree[i]];
            ++ numOfFruit;
            if(basket[tree[i]] == 1) {
                ++ numOfFruitKind;
            }
            
            while(j < i && numOfFruitKind > 2){
                -- basket[tree[j]];
                -- numOfFruit;
                if(basket[tree[j]] == 0) {
                    -- numOfFruitKind;
                }
                ++ j;
            }
            
            ans = max(ans, numOfFruit);
        }
        return ans;
    }
};
