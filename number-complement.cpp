class Solution {
public:
    int findComplement(int num) {
        int mask = 0x1;
        while (mask < num) {
            mask<<=1;
            mask+=1;
        }
        int complement = (num^(~0)) & mask;
        return complement;
    }
};