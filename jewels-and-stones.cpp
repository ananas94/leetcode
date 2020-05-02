class Solution {
    bool isJewel[256]{};
public:
    int numJewelsInStones(string J, string S) {
        int count=0;
        for (auto j: J){
            isJewel[j]=true;
        }
        for (auto s: S){
          if (isJewel[s]) count++;
        }
        return count;
    }
};