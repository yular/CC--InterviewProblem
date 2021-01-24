/*
*
* Tag: Greedy
* Time: O(mnlgn + qn)
* Space: O(n + m)
*/

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        if(languages.size() == 0) {
            return 0;
        }
        
        for(vector<int> &language : languages) {
            sort(language.begin(), language.end());
        }
        
        int m = languages.size(), stuCnt = 0;
        vector<bool> student(m + 1, false);
        for(vector<int> &f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            if(haveCommonLang(u, v, languages)) {
                continue;
            }
            
            if(!student[u]) {
                ++ stuCnt;
            }
            if(!student[v]) {
                ++ stuCnt;
            }
            student[u] = student[v] = true;
        }
        
        int maxLang = 0;
        vector<int> cntLang(n, 0);
        for(int i = 0; i < m ; ++ i) {
            if(!student[i]) {
                continue;
            }
            for(int j = 0; j < languages[i].size(); ++ j) {
                ++ cntLang[languages[i][j] - 1];
                maxLang = max(maxLang, cntLang[languages[i][j] - 1]);
            }
        }
        return stuCnt - maxLang;
    }
private:
    bool haveCommonLang(int u, int v, vector<vector<int>>& languages) {
        for(int i = 0, j = 0; i < languages[u].size() && j < languages[v].size();) {
            if(languages[u][i] == languages[v][j]) {
                return true;
            } else if(languages[u][i] < languages[v][j]) {
                ++ i;
            } else {
                ++ j;
            }
        }
        return false;
    }
};
