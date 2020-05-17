/*
*
* Tag: Sort
* Time: O(mn^2)
* Space: O(nm)
*/

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        if(n == 0) {
            return {};
        }
        
        int idx = 0;
        unordered_map<string, int> dic;
        for(vector<string> coms : favoriteCompanies) {
            for(string com : coms) {
                if(dic.count(com) > 0) {
                    continue;
                }
                
                dic[com] = idx ++;
            }
        }
        
        vector<vector<int>> arr;
        for(vector<string> coms : favoriteCompanies) {
            vector<int> t(coms.size());
            for(int i = 0; i < coms.size(); ++ i) {
                t[i] = dic[coms[i]];
            }
            
            sort(t.begin(), t.end());
            arr.push_back(t);
        }
        
        vector<int> ans;
        for(int i = 0; i < arr.size(); ++ i) {
            bool canFindSuperSet = false;
            for(int j = 0; j < arr.size(); ++ j) {
                if(i == j) {
                    continue;
                }
                
                if(isSubSet(arr[i], arr[j])) {
                    canFindSuperSet = true;
                    break;
                }
            }
            
            if(!canFindSuperSet) {
                ans.push_back(i);
            }
        }
        return ans;
    }
private:
    bool isSubSet(vector<int> a, vector<int> b) {
        if(a.size() > b.size()) {
            return false;
        }
        
        int cnt = 0;
        for(int i = 0, j = 0; i < a.size() && j < b.size(); ) {
            if(a[i] < b[j]) {
                ++ i;
            } else if(b[j] < a[i]) {
                ++ j;
            } else {
                ++ cnt;
                ++ i;
                ++ j;
            }
        }
        return cnt == a.size();
    }
};
