/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    int daysBetweenDates(string date1, string date2) {
        if(date1 > date2) {
            swap(date1, date2);
        }
        
        int y1 = stoi(date1.substr(0, 4)), y2 = stoi(date2.substr(0, 4));
        int d1 = dayOfYear(date1), d2 = dayOfYear(date2);
        int ans = 0;
        if(y1 == y2) {
            ans = d2 - d1;
        } else {
            for(int y = y1 + 1; y < y2; ++ y) {
                if(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
                    ans += 366;
                } else {
                    ans += 365;
                }
            }
            ans += (365 - d1);
            if(y1 % 4 == 0 && (y1 % 100 != 0 || y1 % 400 == 0)) {
                ++ ans;
            }
            
            ans += d2;
        }
        return ans;
    }
    
private:
    int dayOfYear(string date) {
        if(date.size() == 0) {
            return 0;
        }
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8));
        int ans = d;
        if (m > 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)){
            ++ans;
        } 
        while (--m > 0) ans += days[m - 1];
        return ans;
    }
};
