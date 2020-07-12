/*
* 
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    unordered_map<string,string> monthDic = {
        {"Jan", "01"}, 
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };
public:
    string reformatDate(string date) {
        string ans = "";
        string day = getDay(date);
        
        string mon = "";
        int idx = 0;
        for(; idx < date.size(); ++ idx){
            if(date[idx] == ' ') {
                break;
            }
        }
        ++ idx;
        
        for(; idx < date.size(); ++ idx) {
            if(date[idx] == ' ') {
                break;
            }
            
            mon += date[idx];
        }
        mon = monthDic[mon];
        ++ idx;
        
        ans = date.substr(idx) + "-" + mon + "-" + day;
        return ans;
    }
private:
    string getDay(string date) {
        string day = "";
        if(date[1] > '9' || date[1] < '0') {
            day = "0"; 
            day += date[0];
        } else {
            day = date.substr(0, 2);
        }
        return day;
    }
};
