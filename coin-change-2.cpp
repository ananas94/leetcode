class Solution {
public:
 int change(int amount, vector<int>& coins) {
         if(coins.size()==0) return amount==0?1:0;
        int row=coins.size();
        int arr[row][amount+1]; 
        for(int i=0;i<row;i++){
            for(int j=0;j<=amount;j++){
                if(j==0){arr[i][j]=1;
                        continue;}
                if(i==0){
                    if(coins[i]>j)arr[i][j]=0;
                    else arr[i][j]=arr[i][j-coins[i]];
                    continue;
                }
                if(coins[i]>j)arr[i][j]=arr[i-1][j];
                else arr[i][j]=arr[i-1][j]+arr[i][j-coins[i]];
            }
        }
        return arr[row-1][amount];
    }
};