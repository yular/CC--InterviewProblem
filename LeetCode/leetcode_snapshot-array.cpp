/*
*
* Tag: Hash
* Time: O(n) or O(1)
* Space: O(n)
*/

class SnapshotArray {
private:
    vector<unordered_map<int,int>> snapHistory;
    unordered_map<int,int> curSnap;
    int len;
public:
    SnapshotArray(int length) {
        len = length;
    }
    
    void set(int index, int val) {
        curSnap[index] = val;
    }
    
    int snap() {
        snapHistory.push_back(curSnap);
        return snapHistory.size() - 1;
    }
    
    int get(int index, int snap_id) {        
        return snapHistory[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
