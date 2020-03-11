/*
*
* Tag: DFS
* Time: O()
* Space: O(n)
*/

class Solution {
public:
    vector<int> splitIntoFibonacci(string s) {
        if(s.size() == 0){
            return {};
        }
        
        vector<int> ans, tmp(s.size(), 0);
        int cnt = 0;
        dfs(s, tmp, ans, cnt, 0, 0);
        return ans;
    }
    
private:
    void dfs(string &s, vector<int> &tmp, vector<int> &ans, int &cnt, int idx, long long num){
        if(cnt >= 3) {
            if((long long)tmp[cnt - 3] + (long long)tmp[cnt - 2] != (long long)tmp[cnt - 1]) {
                return ;
            }
        }
        
        if(idx >= s.size()) {
            bool isFound = true;
            for(int i = 2; i < cnt; ++ i){
                if(tmp[i - 2] + tmp[i - 1] != tmp[i]) {
                    isFound = false;
                    break;
                }
            }
            if(isFound && cnt >= 3) {
                ans.resize(cnt);
                for(int i = 0; i < cnt; ++ i){
                    ans[i] = tmp[i];
                }
            }
            
            return ;
        }
        
        for(int i = idx; i < s.size(); ++ i){
            num = (num*10) + (s[i] - '0'); 
            if(num > INT_MAX) {
                break;
            }
            
            tmp[cnt ++] = num;
            dfs(s, tmp, ans, cnt, i + 1, 0);
            if(ans.size() > 0){
                return;
            }
            -- cnt;
            if(num == 0) {
                break;
            }
        }
        return ;
    }
};
