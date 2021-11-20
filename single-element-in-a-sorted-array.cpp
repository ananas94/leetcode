class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorsum=0;
        for (int i=0;i<nums.size();i++)
            xorsum ^= nums[i];
        return xorsum^0;
    }
};