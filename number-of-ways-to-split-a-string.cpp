class Solution {
public:
    int numWays(string s) {
        int num=0;
        for (char i: s)
        {
            if ( i == '1' ) num++;
        }
        if (num%3!=0) return 0;
        
        if (num == 0)  return (((s.size()-1) * (s.size() -2 ))/2)% (1000000000+7);
        
        
        int curr = 0;
        int lenFirst =1;
        int lenSecond =1;
        
        for (char i: s)
        {
            if (i=='1') curr++;
            if (i=='0' && curr == num/3 ) lenFirst++;
            if (i=='0' && curr == 2*num/3) lenSecond++;
        }
        return (int) (((int64_t) lenFirst*lenSecond) % (1000000000+7));
        
    }
};