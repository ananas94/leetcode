class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int64_t total=0;
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[0].size();j++) {
                int64_t current=0;
                if (matrix[i][j]) {
                    current++;
                    if (i>0 && j>0) {
                        current += std::min( {matrix[i-1][j-1],matrix[i][j-1],matrix[i-1][j] }   );
                    }
                }
                total += current;
                matrix[i][j]=current;
            }
        }
        return total;
    }
};