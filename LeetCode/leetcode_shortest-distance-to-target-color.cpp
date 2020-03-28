/*
*
* Tag: Sort + Binary Search
* Time: O(nlgn + mlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        if(queries.size() == 0) {
            return {};
        }
        
        unordered_map<int, set<int>> colorArr;
        for(int i = 0; i < colors.size(); ++ i) {
            colorArr[colors[i]].insert(i);
        }
        
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); ++ i) {
            int idx = queries[i][0], col = queries[i][1];
            if(colorArr.count(col) == 0) {
                ans[i] = -1;
                continue;
            }
            
            ans[i] = getColorIdx(idx, colorArr[col]);
        }
        return ans;
    }
private:
    int getColorIdx(int idx, set<int> &arr) {
        auto it = arr.begin();
        auto rit = arr.rbegin();
        if(idx <= *it) {
            return *it - idx;
        }
        if(idx >= *rit) {
            return idx - *rit;
        }
        
        auto cit = arr.lower_bound(idx);
        if(*cit == idx) {
            return 0;
        }
        auto pit = cit;
        pit --;
        return min(idx - *pit, *cit - idx);
    }
};
