/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr.size());
        if(arr.size() == 0){
            return ans;
        }
        
        vector<int> rnk = arr;
        sort(rnk.begin(), rnk.end());
        
        unordered_map<int,int> dict;
        int rank = 1;
        for(int i = 0; i < rnk.size(); ++ i){
            if(dict.count(rnk[i]) != 0){
                continue;
            }
            dict[rnk[i]] = rank;
            ++ rank;
        }
        
        for(int i = 0; i < arr.size(); ++ i){
            ans[i] = dict[arr[i]];
        }
        return ans;
    }
};
