class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        std::queue< std::pair<int,int> > q;
        
        q.emplace(sr,sc);
        int baseColor = image[sr][sc];
        if (newColor==baseColor) return image;
        while (!q.empty())     {
            auto current = q.front(); q.pop();
            if (current.first>=0 && current.first<image.size() &&
                current.second>=0 && current.second<image[0].size()) {
                if (image[current.first][current.second]==baseColor ) { 
                    image[current.first][current.second]=newColor;
                    q.emplace(current.first-1,current.second);
                    q.emplace(current.first+1,current.second);
                    q.emplace(current.first,current.second-1);
                    q.emplace(current.first,current.second+1);
                }
            }
        }
        return image;
    }
};