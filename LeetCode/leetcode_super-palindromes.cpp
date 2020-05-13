/*
*
* Tag: Math, DFS
* Time: O(len*10^(ceil(len/2))) where len is the max length of input string
* Space: O(len*10^(ceil(len/2)))
*/

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int ans = 0;
        long long l = stol(L), r = stol(R);
        if(l > r) {
            return ans;
        }
        
        vector<vector<string>> dic(20);
        for(int i = 0; i < 10; ++ i) {
            if(i >= l && i <= r && (i == 1 || i == 4 || i == 9)) {
                ++ ans;
            }
            
            string v = to_string(i);
            dic[1].push_back(v);
            dic[2].push_back(v + v);
        }
        if(r <= 100) {
            return ans;
        }
        
        countPalindromes(dic, l, r, ans);
        return ans;
    }
private:
    void countPalindromes(vector<vector<string>> dic, long long l, long long r, int &ans) {
        for(int i = 0; i < dic[2].size(); ++ i) {
            long long v = stol(dic[2][i]);
            long long res = v*v;
            if(res >= l && res <= r && isPalindrome(res)) {
                ++ ans;
            }
            if(res > r) {
                return ;
            }
        }
        
        for(int i = 3; i <= 9; ++ i) {
            for(int j = 0; j <= 9; ++ j) {
                string d = to_string(j);
                
                string v = "";
                for(int k = 0; k < dic[i - 2].size(); ++ k) {
                    v = d + dic[i-2][k] + d;
                    dic[i].push_back(v);
                    if(j == 0) {
                        continue;
                    }
                    
                    long long p = stol(v);
                    long long res = p*p;
                    if(res >= l && res <= r && isPalindrome(res)) {
                        ++ ans;
                    }
                    if(res > r) {
                        return ;
                    }
                }
            }    
        }
        
        return ;
    }
    
    bool isPalindrome(long long v) {
        string s = to_string(v);
        for(int l = 0, r = s.size() - 1; l <= r; ++l, --r) {
            if(s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
};
