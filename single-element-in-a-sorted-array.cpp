class Solution {
public:    
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size()==1)
            return nums[0];
        if (nums[nums.size()-1]!=nums[nums.size()-2])
            return nums[nums.size()-1];
        
        // there is nums.size()/2 pairs and one more digit
        // so we are looking for first broken pair and it's first elem 
        int start =0,
            end = nums.size()/2,
            mid = end/2;
        
        
        
        while (start<end) {
            if ( nums[mid*2]== nums[mid*2+1] ) { //all in left is ok
                start = mid +1;
            } else {  //mid pair is broken, so it's under suspection
                end = mid;
            }
            mid = (end+start) /2;
        }
        return nums[start*2];
        
    }
    

};