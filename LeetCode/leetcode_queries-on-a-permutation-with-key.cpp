/*
*
* Tag: Data Structure
* Time: O(m)
* Space: O(m)
*/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        if(queries.size() == 0) {
            return {};
        }
        
        list<int> lst;
        for(int i = 1; i <= m; ++ i) {
            lst.push_back(i);
        }
        
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); ++ i) {
            int v = queries[i], idx = 0;
            for(auto it = lst.begin(); it != lst.end(); it ++, ++ idx) {
                if(*it == v) {
                    ans[i] = idx;
                    lst.erase(it);
                    break;
                }
            }
            lst.push_front(v);
        }
        return ans;
    }
};
