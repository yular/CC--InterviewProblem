/*
*
* Tag: Greedy + Hash
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if(k >= arr.size()) {
            return 0;
        }
        
        unordered_map<int,int> dic;
        for(int v : arr){
            ++ dic[v];
        }
        
        vector<pair<int,int>> list(dic.size());
        int ans = list.size(), idx = 0;
        for(auto it : dic) {
            list[idx ++] = make_pair(it.first, it.second);
        }
        
        sort(list.begin(), list.end(), cmp);
        
        for(int i = 0; i < list.size() && k > 0; ++ i, -- ans) {
            k -= list[i].second;
            if(k <= 0) {
                ans -= k == 0? 1 : 0;
                break;
            }
        }
        return ans;
    }
    
private:
    struct comparator {
        bool operator () (const pair<int,int> &a, const pair<int,int> &b) {
            return a.second < b.second;
        }
    }cmp;
};
