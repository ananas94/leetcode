     template<int N>
        constexpr std::array<int,N+1> precalc() 
        {
            int base=0;
            std::array<int,N+1> ret;
            ret[0]=0;
            for (int i=1; i<=N; i++) {
                if ( (1<<base) == i) { ret[i]=1; base++; }
                else ret[i]= 1+ret[i-(1<<base-1)];
            }
            return ret;
        }

class Solution {

    
    std::vector<int> calc(int n) 
    {
        std::vector<int> ret(n+1);
        int base=0;
        ret[0]=0;
        for (int i=1; i<=n; i++) {
            if ((1<<base) == i) { ret[i]=1; base++;}
            else ret[i]= 1+ret[i-(1<<base-1)];
        }
        return ret;
    }


    std::array<int,66001> pred = precalc<66000>();
public:
    vector<int> countBits(int num) {
        if (num>66000) { return calc(num); }
        else {
            return  vector<int>(pred.begin(),pred.begin()+num+1);
        }
    }
};