/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/

class ParkingSystem {
private:
    unordered_map<int,int> parkingLot;
public:
    ParkingSystem(int big, int medium, int small) {
        parkingLot[1] = big, parkingLot[2] = medium, parkingLot[3] = small;
    }
    
    bool addCar(int carType) {
        if(parkingLot.count(carType) == 0 || parkingLot[carType] <= 0) {
            return false;
        }
        
        -- parkingLot[carType];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
