/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    vector<string> days = {"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};
    vector<int> daysOfMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
public:
    string dayOfTheWeek(int day, int month, int year) {
        int totDays = day;
        for(int i = 1971; i < year; ++ i) {
            totDays += 365;
            if(isLunarYear(i)){
                ++ totDays;
            }
        }
        for(int i = 0; i < month - 1; ++ i){
            totDays += daysOfMonth[i];
        }
        
        if(month > 2 && isLunarYear(year)) {
            ++ totDays;
        }
        return days[totDays%7];
    }
private:
    bool isLunarYear(int year) {
        return (year%100 != 0 && year%4 == 0) || (year%400 == 0 && year%100 == 0);
    }
};
