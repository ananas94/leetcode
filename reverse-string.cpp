class Solution {
public:
    void reverseString(vector<char>& s) {
        std::reverse(s.begin(), s.end());
        /*auto first = 0;
        auto last = s.size();
        while ((first != last) && (first != --last)) {
            auto tmp = s[first];
            s[first]=s[last];
            s[last]=tmp;
            first++;
        }*/
    }
};