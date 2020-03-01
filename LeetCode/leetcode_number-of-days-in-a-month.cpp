/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
private:
    int numOfDaysOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
public:
    int numberOfDays(int Y, int M) {
        return isLunarYear(Y) && M == 2?  numOfDaysOfMonth[M] + 1 : numOfDaysOfMonth[M];
    }
private:
    bool isLunarYear(int y) {
        return y%400 == 0 || (y%4 == 0 && y%100 != 0);
    }
};
