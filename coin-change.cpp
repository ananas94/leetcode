class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> reachIn;
        reachIn.resize(amount+1, amount+2);
        reachIn[0]=0;
        for (unsigned int i = 0; i<amount; i++)
        {
            for (int nom : coins)
            {
                if ( (i+nom<=amount) && (reachIn[i]+1) < reachIn[i+nom])
                    reachIn[i+nom] = reachIn[i]+1;
            }
        }
        return reachIn[amount]==amount+2 ? -1 : reachIn[amount];
    }
};