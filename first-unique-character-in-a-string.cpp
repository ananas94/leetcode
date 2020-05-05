class Solution {
public:
    int firstUniqChar(string s) {
        int letters[255]{};
        int counter=0;
        for (auto l: s) letters[l]++;
        
        for (auto l: s) if (letters[l]==1) return counter; else counter++;
        return -1;
    }
};