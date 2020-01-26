/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ans = 0;
        if(indices.size() == 0){
            return ans;
        }
        
        vector<int> rcnt(n, 0), ccnt(m, 0);
        for(vector<int> indice : indices){
            ++ rcnt[indice[0]];
            ++ ccnt[indice[1]];
        }
        
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                int sum = rcnt[i] + ccnt[j];
                if((sum&1) == 1){
                    ++ ans;
                }
            }
        }
        return ans;
    }
};
