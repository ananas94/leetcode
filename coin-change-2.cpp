class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::array<int, 5002> ways{};
        ways[0]=1;
        for (int nom: coins)
        {
            for (int i=0;i<=amount;i+=1)
            {
                if (i-nom>=0) {
                    ways[i]+=ways[i-nom];
                }
            }
        }
        return ways[amount];
    }
};