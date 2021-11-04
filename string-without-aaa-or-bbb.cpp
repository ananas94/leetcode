class Solution {
public:
    string strWithout3a3b(int a, int b) {
        std::string ret;
        ret.reserve(a+b+1);
        int i=0;
        while (a-b>=2 && a && b)
        {
            ret.push_back('a');
            ret.push_back('a');
            ret.push_back('b');
            a-=2;
            b-=1;
        }
        while (b-a>=2 && a && b )
        {
            ret.push_back('b');
            ret.push_back('b');
            ret.push_back('a');
            b-=2;
            a-=1;
        }
        while (a && b)
        {
            ret.push_back('b');
            ret.push_back('a');
            a--;
            b--;
        }
        while (a) { ret.push_back('a'); a--;}
        while (b) { ret.push_back('b'); b--;}
        return ret;   
    }
};