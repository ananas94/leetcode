class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size()<=2) return true;
        
        auto firstX = coordinates[1][0] - coordinates[0][0];
        auto firstY = coordinates[1][1] - coordinates[0][1];
        for (int i=1; i<coordinates.size();i++) {
            auto currentX = coordinates[i][0] - coordinates[i-1][0];
            auto currentY = coordinates[i][1] - coordinates[i-1][1];
            if (firstX*currentY!=currentX*firstY) return false;
        }        
        return true;
    }
};