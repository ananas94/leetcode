class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int prev = numeric_limits<int>::max();
        for (int i : prices)
        {
            if (i-prev>0) ret += i-prev;
            prev = i;
        }
        return ret;
    }
};