/*
*
* Tag: Hash + Design
* Time: create path: O(n), get: O(1)
* Space: O(n^2)
*/

class FileSystem {
private:
    unordered_map<string,int> pathDict;
public:
    FileSystem() {
        pathDict.clear();
        pathDict["/"] = 0;
    }
    
    bool createPath(string path, int value) {
        if(pathDict.count(path) != 0) {
            return false;
        }
        
        string curPath = "";
        for(int i = 0; i < path.size() - 1; ++ i) {
            char c = path[i];
            curPath += c;
            if(i == 0 || path[i + 1] == '/') {
                if(pathDict.count(curPath) == 0) {
                    return false;
                }
            }
        }
        
        pathDict[path] = value;
        return true;
    }
    
    int get(string path) {
        return pathDict.count(path) == 0? -1 : pathDict[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
