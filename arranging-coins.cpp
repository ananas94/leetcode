class Solution {
public:
    int arrangeCoins(int n) {
        int64_t k=1;
        while ((k)*(k+1)/2 <= n) k++;
        return k-1;
    }
};