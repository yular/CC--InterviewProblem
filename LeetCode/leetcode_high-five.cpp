/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> ans;
        if(items.size() == 0){
            return ans;
        }
        
        sort(items.begin(), items.end(), cmp);
        
        for(int i = 0; i < items.size(); ){
            int curId = items[i][0], sum = 0, tot = 0;
            for(; i < items.size() && items[i][0] == curId; ++ i){
                if(tot >= 5) {
                    continue;
                }
                
                sum += items[i][1];
                ++ tot;
            }
            
            vector<int> score = {curId, sum/tot};
            ans.push_back(score);
        }
        return ans;
    }
private:
    struct comparator{
        bool operator() (const vector<int> &a, const vector<int> &b){
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        }
    }cmp;
};
