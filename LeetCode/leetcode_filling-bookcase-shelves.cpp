/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        if(books.size() == 0) {
            return 0;
        }
        
        int n = books.size();
        vector<vector<int>> shelf(n, vector<int>(n, -1));
        for(int i = 0; i < n; ++ i) {
            int totWid = 0, maxHgh = 0;
            for(int j = i; j < n; ++ j) {
                totWid += books[j][0];
                maxHgh = max(maxHgh, books[j][1]);
                if(totWid > shelf_width) {
                    break;
                }
                shelf[i][j] = maxHgh;
            }
        }
        
        vector<int> dp(n, INT_MAX);
        for(int i = 0; i < n; ++ i) {
            for(int j = i; j >= 0; -- j) {
                if(shelf[j][i] == -1) {
                    break;
                }
                
                if(j == 0) {
                    dp[i] = min(dp[i], shelf[0][i]);
                } else {
                    dp[i] = min(dp[i], dp[j - 1] + shelf[j][i]);
                }
            }
        }
        return dp[n - 1];
    }
};
