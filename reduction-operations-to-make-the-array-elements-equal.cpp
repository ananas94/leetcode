class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int level = *nums.rbegin();
        int levelLength=0;
        int sumOp = 0;
        for (auto it=nums.rbegin(); it!=nums.rend(); it++)
        {
            if (level != *it) {
                level = *it;
                sumOp+=levelLength;                
            }
            levelLength++;
        }
        return sumOp;
    }
};