class Solution {
public:
    int rob(vector<int>& nums) {
        int oneBack=0, twoBack=0;
        for (int i : nums)
        {
            int tmp = oneBack;
            oneBack = std::max(oneBack, twoBack+i);
            twoBack = tmp;
        }
        return oneBack;
    }
};