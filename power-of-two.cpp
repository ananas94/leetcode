class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        unsigned int i=1;
        while (i<n) i<<=1;
        return i==n;
    }
};