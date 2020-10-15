/*
*
* Tag: Binary Search
* Time: O(nlgm)
* Space: O(1)
*/

/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        if(text.size() == 0 || fonts.size() == 0) {
            return -1;
        }
        
        int ans = -1, l = 0, r = fonts.size() - 1;
        while(l <= r) {
            int mid = (l + r)/2;
            if(isValidFont(text, fonts[mid], w, h, fontInfo)) {
                ans = fonts[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
private:
    bool isValidFont(string &text, int font, int w, int h, FontInfo fontInfo) {
        if(fontInfo.getHeight(font) > h) {
            return false;
        }
        
        int totW = 0;
        for(int i = 0; i < text.size(); ++ i) {
            char c = text[i];
            totW += fontInfo.getWidth(font, c);
            if(totW > w) {
                return false;
            }
        }
        return true;
    }
};
