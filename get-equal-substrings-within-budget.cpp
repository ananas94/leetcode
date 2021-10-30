class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start=0, end=0, sum=0;
        while (end<s.size())
        {
            sum+=std::abs(s[end]-t[end]);
            end++;
            if (sum>maxCost)
            {
                sum-=abs(s[start]-t[start]);
                start++;
            }
        }
        return end-start;
    }
    
};