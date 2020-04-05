/*
*
* Tag: Geometery
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2) {
            return true;
        }
        
        vector<vector<pair<int,int>>> segments = {{make_pair(x1, y1), make_pair(x1, y2)}, {make_pair(x2, y1), make_pair(x2, y2)}, {make_pair(x1, y1), make_pair(x2, y1)}, {make_pair(x1, y2), make_pair(x2, y2)}};
        
        pair<int,int> center = make_pair(x_center, y_center);
        for(vector<pair<int,int>> seg : segments) {
            if(isSegCrossCir(seg, radius, center)) {
                return true;
            }
        }
        return false;
    }
private:
    bool isSegCrossCir(vector<pair<int,int>> &seg, int r, pair<int,int> &center) {
        for(pair<int,int> pnt : seg) {
            if(isInCir(pnt, r, center)) {
                return true;
            }
        }
        
        int dis = 0;
        if(seg[0].first == seg[1].first) {
            dis = abs(seg[0].first - center.first);
        } else {
            dis = abs(seg[0].second - center.second);
        }
        if(dis > r) {
            return false;
        }
        
        int angle1 = (center.first - seg[0].first) * (seg[1].first - seg[0].first) + (center.second - seg[0].second) * (seg[1].second - seg[0].second);
        int angle2 = (center.first - seg[1].first) * (seg[0].first - seg[1].first) + (center.second - seg[1].second) * (seg[0].second - seg[1].second);
        if (angle1 > 0 && angle2 > 0) return true;
        return false;
    }
    
    bool isInCir(pair<int,int> &pnt, int r, pair<int,int> &center) {
        return (center.first - pnt.first) * (center.first - pnt.first) + (center.second - pnt.second) * (center.second - pnt.second) <= r*r;
    }
};
