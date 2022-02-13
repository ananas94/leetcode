class Solution {
public:
    int myAtoi(string s) {
        bool sign=false;
        int index=0;
        long long base=0;
        while (s[index] && s[index]==' ')
            index++;
        if (s[index]=='-' ) { sign=true; index++; }
        else if (s[index]=='+') { index++; }
        while (s[index] && s[index]>='0' && s[index]<='9' ) {
            long long digit = s[index]-'0';
            base= base* 10 + digit;
            index++;
            if (!sign && base>std::numeric_limits<int32_t>::max()) return std::numeric_limits<int32_t>::max();
            if (sign && base>std::abs(std::numeric_limits<int32_t>::min())) return std::numeric_limits<int32_t>::min();
        }
        return base * (sign ? -1 : 1);
    }
};