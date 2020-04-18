/*
*
* Tag: Hash
* Time: O(mlgm)
* Space: O(m)
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        if(n == 0) {
            return 0;
        }
        if(reservedSeats.size() == 0) {
            return n*2;
        }
        
        map<int,vector<bool>> dict;
        for(vector<int> seat : reservedSeats) {
            if(dict.count(seat[0]) == 0) {
                vector<bool> tmp(11, false);
                dict[seat[0]] = tmp;
            }
            dict[seat[0]][seat[1]] = true;
        }
        
        int ans = 0, curRow = 1;
        for(pair<int, vector<bool>> seat : dict) {
            if(seat.first > curRow) {
                ans += 2*(seat.first - curRow);
            }
            curRow = seat.first + 1;
            if(seat.second[2] == false && seat.second[3] == false && seat.second[4] == false && seat.second[5] == false) {
                ++ ans;
            }
            if(seat.second[6] == false && seat.second[7] == false && seat.second[8] == false && seat.second[9] == false) {
                ++ ans;
                continue;
            }
            if(seat.second[4] == false && seat.second[5] == false && seat.second[6] == false && seat.second[7] == false && (seat.second[2] == true || seat.second[3] == true)) {
                ++ ans;
            }
        }
        
        if(curRow <= n) {
            ans += 2*(n - curRow + 1);
        }
        return ans;
    }
};
