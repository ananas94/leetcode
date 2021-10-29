class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int steps = 0;
        std::vector<std::pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j=0; j<grid[i].size();j++)
            {
                if (grid[i][j]==2)
                    q.emplace_back(i,j);
            }
        while (!q.empty())
        {
            std::vector<std::pair<int, int>> qnext;
            for (auto it : q)            
            {
                int x = it.first;
                int y = it.second;
                if (x-1>=0 && grid[x-1][y]==1)
                {
                    qnext.emplace_back(x-1,y);
                    grid[x-1][y]=2;
                }
                if (y-1>=0 && grid[x][y-1]==1)
                {
                    qnext.emplace_back(x,y-1);
                    grid[x][y-1]=2;
                }
                if (y+1<grid[x].size() && grid[x][y+1]==1)
                {
                    qnext.emplace_back(x,y+1);
                    grid[x][y+1]=2;
                }
                if (x+1<grid.size() && grid[x+1][y]==1)
                {
                    qnext.emplace_back(x+1,y);
                    grid[x+1][y]=2;
                }   
            }
            if (!qnext.empty()) steps++;
            std::swap(q,qnext);
        }
        for (auto row: grid)
        {
            for (auto orange: row)
            {
                if (orange == 1) return -1;
            }
        }
        return steps;
    }
};