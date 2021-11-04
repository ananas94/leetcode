class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sumUpper = 0;
        for (int val:grid[0]) sumUpper +=val;
        sumUpper -= grid[0][0];
        long long sumDown =0;
        long long min = sumUpper;        
        
        for (int i=1;i<grid[0].size();i++)
        {
            sumUpper -= grid[0][i];
            sumDown += grid[1][i-1];
            if (min > std::max(sumUpper,sumDown)) min = std::max(sumUpper,sumDown);
        }
        return min;       
    }
};