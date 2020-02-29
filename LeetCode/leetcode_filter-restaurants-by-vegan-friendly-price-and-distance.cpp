/*
*
* Tag: Sort + Implementation
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> ans;
        if(restaurants.size() == 0) {
            return ans;
        }
        
        vector<vector<int>> filteredRestaurants;
        for(vector<int> rest : restaurants){
            if((veganFriendly == 0 || rest[2] == veganFriendly) && rest[3] <= maxPrice && rest[4] <= maxDistance){
                filteredRestaurants.push_back(rest);
            }
        }
        
        sort(filteredRestaurants.begin(), filteredRestaurants.end(), cmp);
        
        ans.resize(filteredRestaurants.size());
        for(int i = 0; i < ans.size(); ++ i){
            ans[i] = filteredRestaurants[i][0];
        }
        return ans;
    }
    
private:
    struct comparator {
        bool operator() (const vector<int> &a, const vector<int> &b){
            return a[1] == b[1] ? b[0] < a[0] : b[1] < a[1];
        }
    }cmp;
};
