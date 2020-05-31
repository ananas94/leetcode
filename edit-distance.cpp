class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> D(word1.size()+1,vector<int>(word2.size()+1));
        for (int i=0;i<word1.size()+1;i++) {
            D[i][0]=i;
        }
        for (int i=0;i<word2.size()+1;i++) {
            D[0][i]=i;
        }
        
        for (int i=1;i<=word1.size();i++) {
            for (int j=1;j<=word2.size();j++){
              //  std::cout << "i "<<i<<" j " << j;
                D[i][j]=std::min( {
                    D[i-1][j]+1,
                    D[i][j-1]+1, 
                    D[i-1][j-1]+ (word1[i-1]==word2[j-1] ? 0: 1) }  );
               // std::cout<<" D " << D[i][j] << endl; 
            }
        }
        
        return D[word1.size()][word2.size()];
    }
};