/*
*
* Tag: Hash
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string,int>> tableOrder;
        set<string> food;
        for(vector<string> order : orders) {
            int id = stoi(order[1]);
            ++ tableOrder[id][order[2]];
            if(food.count(order[2]) == 0) {
                food.insert(order[2]);
            }
        }
        
        vector<vector<string>> ans;
        vector<string> header(1);
        header[0] = "Table";
        for(string f : food) {
            header.push_back(f);
        } 
        ans.push_back(header);
        
        for(auto it : tableOrder) {
            vector<string> row(header.size(), "0");
            row[0] = to_string(it.first);
            for(int i = 1; i < header.size(); ++ i) {
                int cnt = tableOrder[it.first][header[i]];
                row[i] = to_string(cnt);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
