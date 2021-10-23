class Solution {
public:
    int candy(vector<int>& ratings) {
        int lenDown =0, current = 1, peak = 1;
        int ret = 1;
        for (int i=1; i<ratings.size(); i++)
        {
            if ( ratings[i-1] == ratings[i] )
            {
                lenDown = 0;
                current = 1;
                peak = current;
            }
            else if ( ratings [i-1] < ratings[i] )
            {
                current++;
                lenDown = 0;
                peak = current;
            } 
            else
            {
                current = 1;
                ret += lenDown;
                lenDown++;
                if ( lenDown >= peak ) ret++;
                
            }
            ret+=current;
        }
        return ret;
    }
};