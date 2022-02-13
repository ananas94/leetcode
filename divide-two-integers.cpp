class Solution {
public:
    unsigned int abs2u(int x){
        if (x==std::numeric_limits<int>::min()) return 1<<31;
        else if (x>0) return x;
        else return -x;
    }
    int divide(int dividend, int divisor) {
        if (dividend==std::numeric_limits<int>::min() && divisor==-1)
            return std::numeric_limits<int>::max();
        int sign = 1;
        if (!(dividend>0 && divisor>0 || dividend<0 && divisor<0))  sign = -1;
        unsigned int d1 = abs2u(dividend),
                    d2 = abs2u(divisor);
        unsigned int q=0;
        while (d1>=d2) {
            unsigned int add = 1;
            unsigned int minus = d2;
            for (int i=0; i<32;i++){
                if (d1>minus && d1>minus<<1 ){
                    minus <<=1;
                    add<<=1;
                }
                else 
                    break;
            }
            q+=add;
            d1-=minus;
        }
        return q*sign;
    }
};