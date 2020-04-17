/*
*
* Tag: Hash
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
private:
    struct trans{
        string name, city, transaction;
        int time, amount;
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        if(transactions.size() == 0) {
            return {};
        }
        
        vector<trans> trs(transactions.size());
        for(int i = 0; i < transactions.size(); ++ i) {
            int idx = 0;
            string v = "";
            trans t;
            for(int j = 0; j < transactions[i].size(); ++ j) {
                if(transactions[i][j] == ',' || j == transactions[i].size() - 1) {
                    if(idx == 0) {
                        t.name = v;
                    } else if(idx == 1) {
                        t.time = stoi(v);
                    } else if(idx == 2) {
                        t.amount = stoi(v);
                    } else {
                        t.city = v;
                    }
                    v = "";
                    ++ idx;
                    continue;
                }
                
                v += transactions[i][j];
            }
            t.transaction = transactions[i];
            trs[i] = t;
        }
        
        unordered_map<string, vector<int>> dict;
        vector<bool> isValid(trs.size(), true);
        for(int i = 0; i < trs.size(); ++ i){
            //cout<<trs[i].name<<", "<<trs[i].amount<<", "<<trs[i].time<<", "<<trs[i].city<<endl;
            if(trs[i].amount > 1000) {
                isValid[i] = false;
            }
            if(dict.count(trs[i].name) == 0) {
                dict[trs[i].name].push_back(i);
                continue;
            }
            for(int j : dict[trs[i].name]){
                if(trs[j].city != trs[i].city && abs(trs[i].time - trs[j].time) <= 60) {
                    isValid[j] = isValid[i] = false;
                }
            }
            dict[trs[i].name].push_back(i);
        }
        
        vector<string> ans;
        for(int i = 0; i < isValid.size(); ++ i){
            if(isValid[i]) {
                continue;
            }
            
            ans.push_back(trs[i].transaction);
        }
        return ans;
    }
};
