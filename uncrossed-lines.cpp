class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if ( !A.size() || !B.size() ) return 0;
        vector<vector<int>> dp(A.size()+1, 
                              vector<int>(B.size()+1,0));
        
        for (int i=A.size()-1;i>=0;i--) {
            for (int j=B.size()-1;j>=0;j--){
                dp[i][j] = std::max ( {
                    dp[i][j+1],
                    dp[i+1][j],
                    dp[i+1][j+1]+ (A[i]==B[j]?1:0)
                    }
                );
            }
        }
        return dp[0][0];
    }
};