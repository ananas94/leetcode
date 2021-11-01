class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorSum=0;
        for (int i=1;i<=nums.size();i++)
            xorSum^=i;
        for (int i=0;i<nums.size();i++)
            xorSum^=nums[i];
        return xorSum;
    }
};