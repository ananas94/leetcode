class Solution {
public:
    void solve(vector<vector<char>>& board) {
        std::queue< std::pair<int,int>> q;
        int n =board.size();
        int m = board[0].size();
        for (int i=0;i<n;i++)
        {
           if ( board[i][0] == 'O' )
           {
                   q.emplace(i,0);
                   board[i][0] = 'o';
           }
           if ( board[i][m-1] == 'O' )
           {
                   q.emplace(i,m-1);
                   board[i][m-1] = 'o';
           }
        }
        for (int j=0;j<m;j++)
        {
           if ( board[0][j] == 'O' )
           {
                   q.emplace(0,j);
                   board[0][j] = 'o';
           }
           if ( board[n-1][j] == 'O' )
           {
                   q.emplace(n-1,j);
                   board[n-1][j] = 'o';
           }
        }
        std::cout << q.size() <<std::endl;
        while (!q.empty())
        {
                auto elem = q.front();
                int x = elem.first;
                int y = elem.second;
                q.pop();
                if (x+1<n && board[x+1][y]=='O')
                {
                    board[x+1][y]='o';
                    q.emplace(x+1,y);
                }
                if (x-1>=0 && board[x-1][y]=='O')
                {
                    board[x-1][y]='o';
                    q.emplace(x-1,y);
                }
                if (y+1<m && board[x][y+1]=='O')
                {
                    board[x][y+1]='o';
                    q.emplace(x,y+1);
                }
                if (y-1>=0 && board[x][y-1]=='O')
                {
                    board[x][y-1]='o';
                    q.emplace(x,y-1);
                }                
       }
       for (int i=0;i<n;i++)
       {
           for (int j=0;j<m;j++)
           {
                    if ( board[i][j] == 'o' )
                        board[i][j]='O';
                    else
                        board[i][j]='X';
           }
        }
           
    }
};