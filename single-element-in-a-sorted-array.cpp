class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorsum=0;
        for (int i : nums)
            xorsum ^= i;
        return xorsum^0;
    }
};