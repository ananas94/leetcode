class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max=0;
        for (int i=0;i<nums.size();i++)
        {
            if (i>max) break;
            if (max < i+nums[i]) max = i+nums[i];
        }
        return max>=(nums.size()-1);
    }
};