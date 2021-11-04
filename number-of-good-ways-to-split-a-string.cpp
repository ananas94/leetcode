class Solution {
public:
    int numSplits(string s) {
        std::vector<int> perChar['z'-'a'+1];
        std::unordered_set<char> tailLetters;
        int headsDifferentLetters=0;
        for (int i=0;i<s.size();i++)
        {
            perChar[s[i]-'a'].push_back(i);
        }
        
        for (int i=0;i<'z'-'a'+1; i++)
            if (!perChar[i].empty()) headsDifferentLetters++;
        
        int ret = 0;
        for (int i=s.size()-1;i>0;i--)
        {
            tailLetters.insert(s[i]);
            perChar[s[i]-'a'].pop_back();
            if (perChar[s[i]-'a'].empty()) headsDifferentLetters--;
            if (headsDifferentLetters==tailLetters.size()) ret++;
        }
        return ret;
    }
};