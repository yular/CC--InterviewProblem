/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    string arrangeWords(string text) {
        if(text.size() == 0) {
            return "";
        }
        text += " ";
        
        vector<pair<string,int>> arr;
        string s = "";
        int idx = 0;
        for(int i = 0; i < text.size(); ++ i) {
            if(text[i] == ' ') {
                arr.push_back(make_pair(s, idx ++));
                s = "";
                continue;
            }
            
            s += tolower(text[i]);
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        string ans = "";
        arr[0].first[0] = toupper(arr[0].first[0]);
        ans += arr[0].first;
        for(int i = 1; i < arr.size(); ++ i) {
            ans += " ";
            ans += arr[i].first;
        }
        return ans;
    }
private:
    struct chainComparator{
        bool operator() (const pair<string,int> &a, const pair<string,int> &b){
            return a.first.size() == b.first.size() ? a.second < b.second : a.first.size() < b.first.size();
        }
    }cmp;
};
