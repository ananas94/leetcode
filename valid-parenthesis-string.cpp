class Solution {
public:
    bool checkValidString(string s) {
        int minOpenNum=0,maxOpenNum=0;
        for (auto c: s)  {
            if (c!=')') maxOpenNum++;            
            else maxOpenNum--;
            
            if (c=='(') minOpenNum++;
            else minOpenNum--; 
            
            if (maxOpenNum<0) return false;

            if (minOpenNum<0) minOpenNum=0;
        }
        return minOpenNum == 0;
    }
};