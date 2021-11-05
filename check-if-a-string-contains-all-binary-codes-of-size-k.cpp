class Solution {
public:
    bool hasAllCodes(string s, int k) {
        std::unordered_set<int> S;
        unsigned int mask = 0;
        for (int i=0; i<k;i++)
        {
            mask = mask << 1;
            mask++;
        }   
        unsigned int window=0;
        int counter =0;
        for (char c : s)
        {
            window= ((window<<1) + (c-'0'))&mask;
            counter++;
            if (counter>=k) S.insert(window);
        }
        return S.size() == (1 << k);        
    }
};