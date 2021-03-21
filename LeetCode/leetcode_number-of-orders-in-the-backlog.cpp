/*
*
* Tag: Data Structure ( AVL )
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
    struct Order {
        int amount, price, type;
    };
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        if(orders.size() == 0) {
            return 0;
        }
        
        map<int,long long> sellbacklog, buybacklog;
        for(vector<int> order : orders) {
            int price = order[0], amount = order[1], type = order[2];
            if(type == 0) {
                while(sellbacklog.size() > 0 && amount > 0) {
                    auto it = sellbacklog.begin();
                    if(it->first > price) {
                        break;
                    }
                    if(it->second <= amount) {
                        amount -= it->second;
                        sellbacklog.erase(it);
                    } else {
                        it->second -= amount;
                        amount = 0;
                    }
                }
                if(amount <= 0) {
                    continue;
                }
                buybacklog[price] += amount;
            } else {
                while(buybacklog.size() > 0 && amount > 0) {
                    auto it = buybacklog.rbegin();
                    if(it->first < price) {
                        break;
                    }
                    if(it->second <= amount) {
                        amount -= it->second;
                        buybacklog.erase(it->first);
                    } else {
                        it->second -= amount;
                        amount = 0;
                    }
                }
                if(amount <= 0) {
                    continue;
                }
                sellbacklog[price] += amount;
            }
        }
        
        long long ans = 0;
        for(auto it : sellbacklog) {
            ans += it.second;
            ans %= MOD;
        }
        for(auto it : buybacklog) {
            ans += it.second;
            ans %= MOD;
        }
        return ans;
    }
};
