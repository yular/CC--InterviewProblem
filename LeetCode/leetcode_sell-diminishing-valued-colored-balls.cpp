/*
*
* Tag: Greedy + Sort + Math
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    long long MOD = 1e9 + 7;
public:
    int maxProfit(vector<int>& inventory, int orders) {
        if(orders <= 0  || inventory.size() == 0) {
            return 0;
        }
        
        int n = inventory.size();
        map<int,int> numDict;
        for(int i = 0; i < n; ++ i) {
            ++ numDict[inventory[i]];
        }
        
        long long ans = 0;
        for(auto it = numDict.rbegin(); it != numDict.rend() && orders > 0; ++ it) {
            auto jt = it;
            ++ jt;
            
            long long diff = it->first;
            if(jt != numDict.rend()) {
                diff = it->first - jt->first;
            }
            
            long long num = it->first, cnt = it->second;
            long long tot = diff*cnt;
            if(tot <= orders) {
                orders -= tot;
                long long tmp = getAttainedValue(num, diff);
                ans += (tmp*cnt)%MOD;
            } else {
                diff = orders/cnt;
                long long tmp = getAttainedValue(num, diff);
                ans += (tmp*cnt)%MOD;
                ans %= MOD;
                
                long long rest = orders % cnt;
                tmp = num - diff;
                ans += (tmp*rest)%MOD;
                
                orders = 0;
            }
            
            ans %= MOD;
            if(orders > 0) {
                numDict[jt->first] += it->second;
            }
        }
        return ans;
    }
private:
    long long getAttainedValue(long long num, long long cnt) {
        long long res = 0;
        if(cnt&1) {
            res = ((((cnt - 1)/2)%MOD)*cnt)%MOD;
        } else {
            res = (((cnt/2)%MOD)*(cnt - 1))%MOD;
        }
        res = ((num*cnt)%MOD - res + MOD)%MOD;
        return res%MOD;
    }
};
