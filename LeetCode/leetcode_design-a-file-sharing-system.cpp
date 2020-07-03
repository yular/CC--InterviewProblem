/*
*
* Tag: Data Structure (Hash Map + Tree Map)
* Time: O(nlgn) or O(mlgm)
* Space: O(nm)
*/

class FileSharing {
private:
    unordered_map<int,set<int>> fileOwnersDict;
    unordered_map<int,unordered_set<int>> ownerFilesDict;
    priority_queue<int, vector<int>, greater<int>> userIDsQue;
    int idx = 1;
public:
    FileSharing(int m) {
    }
    
    int join(vector<int> ownedChunks) {
        int userID;
        if(!userIDsQue.empty()){
            userID = userIDsQue.top();
            userIDsQue.pop();
        } else {
            userID = idx++;
        }
        
        for(int chunkID : ownedChunks) {
            ownerFilesDict[userID].insert(chunkID);
            fileOwnersDict[chunkID].insert(userID);
        }
        return userID;
    }
    
    void leave(int userID) {
        for(int chunkID : ownerFilesDict[userID]) {
            fileOwnersDict[chunkID].erase(userID);
        }
        
        ownerFilesDict.erase(userID);
        userIDsQue.push(userID);
        return ;
    }
    
    vector<int> request(int userID, int chunkID) {
        if(fileOwnersDict.count(chunkID) == 0 || fileOwnersDict[chunkID].size() == 0) {
            return {};
        }
        
        vector<int> ans(fileOwnersDict[chunkID].begin(), fileOwnersDict[chunkID].end());
        
        fileOwnersDict[chunkID].insert(userID);
        ownerFilesDict[userID].insert(chunkID);
        return ans;
    }
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */
