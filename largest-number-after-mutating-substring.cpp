class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool replacementStarted = false;
        bool replacementEnded = false;
        for (int i = 0; i<num.size(); i++)
        {
            if (!replacementStarted && !replacementEnded && change[num[i]-'0']>(num[i]-'0'))
            {
                replacementStarted = true;
            } 
            if (replacementStarted && !replacementEnded && change[num[i]-'0']>=(num[i]-'0'))
            {
                num[i]= change[num[i]-'0'] + '0';               
            } else if (replacementStarted) {
                replacementEnded = true;
            }
        }
        return num;
    }
};