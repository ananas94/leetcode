class Solution {
public:
    string removeKdigits(string num, int k) {
        string answer;
        for (auto c: num) {
            while (answer.length() && answer.back()>c && k)  {
                k--;
                answer.pop_back();
            }
            if (answer.length() || c!='0' ) answer.push_back(c);
        }
        while (answer.length() && k ) { answer.pop_back(); k--; }
        if (answer.size()==0) return "0";
        else return answer;
    }
};