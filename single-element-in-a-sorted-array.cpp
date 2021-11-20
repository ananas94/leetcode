class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorsum=0;
        int s = nums.size();
        for (int i=0;i<s;i++)
            xorsum ^= nums[i];
        return xorsum^0;
    }
};