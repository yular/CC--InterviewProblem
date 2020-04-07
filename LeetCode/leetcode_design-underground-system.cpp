/*
*
* Tag: Data Structure, Hash
* Time: O(1)
* Space: O(n)
*/

class UndergroundSystem {
private:
    unordered_map<int, pair<string,long long>> customerCurState;
    unordered_map<string, unordered_map<string, pair<long long,int>>> travelHistory;
public:
    UndergroundSystem() {
        customerCurState.clear();
        travelHistory.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        customerCurState[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        if(customerCurState.count(id) == 0 ) {
            return ;
        }
        
        if(travelHistory[customerCurState[id].first].count(stationName) == 0) {
            travelHistory[customerCurState[id].first][stationName] = make_pair(0, 0);
        }
        travelHistory[customerCurState[id].first][stationName].first += t - customerCurState[id].second;
        ++ travelHistory[customerCurState[id].first][stationName].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        if(travelHistory.count(startStation) == 0 || travelHistory[startStation].count(endStation) == 0 || travelHistory[startStation][endStation].second == 0) {
            return 0.0;
        }
        
        long long t = travelHistory[startStation][endStation].first;
        return (double)t/(double)travelHistory[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
