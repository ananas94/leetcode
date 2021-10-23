class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right = nums.size()-1, middle;
        while (left<right)
        {
            middle = left + (right -left)/2;
            if ( nums[middle] > nums[right] ) left = middle+1;
            else if (nums[middle]<nums[left]) right = middle;
            else right--;
        }
        return nums[left];
    }
};