class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::map<int,int> sums;
        int sum=0,
            max=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==0) {
                sum--;
            } else if (nums[i]==1) {
                sum++;
            }
            if (!sums.count(sum)) sums[sum]=i;
         //    cout<<sum << " " << sums[sum] << std::endl;
            if (sums.count(sum) && (i-sums[sum]) > max ) max = i - sums[sum];
            if (sum == 0 ) max= i+1;
        }
        return max;
    }
};