/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour == 12 ? 0 : hour;
        double ang = fabs(minutes*6.0 - hour*30 - 0.5*minutes);
        return min(ang, 360 - ang);
    }
};
