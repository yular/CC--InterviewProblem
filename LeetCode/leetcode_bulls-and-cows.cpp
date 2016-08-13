/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        int cntb = 0, cntc = 0;
       // string ans;
        int vis[10];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < secret.size(); ++ i){
            ++ vis[secret[i] - '0'];
        }
        
        for(int i = 0; i < secret.size(); ++ i){
            if(secret[i] == guess[i]){
                ++ cntb;
                -- vis[guess[i] - '0'];
            }
        }
        for(int i = 0; i < secret.size(); ++ i){
            if(secret[i] != guess[i]){
                if(vis[guess[i] - '0']){
                    ++ cntc;
                    -- vis[guess[i] - '0'];
                }
            }
        }
        string ans = "";
        ans += getVal(cntb);
        ans += "A";
        ans += getVal(cntc);
        ans += "B";
        return ans;
    }
private:
    string getVal(int val){
        string res = "";
        if(!val)
            return "0";
        while(val){
            res += ((val%10)+'0');
            val /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
