class Solution {
    int m_magazine[255]{};
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (auto c: magazine) this->m_magazine[c]++;
        for (auto r: ransomNote) if (this->m_magazine[r]==0) return false; else  this->m_magazine[r]--;
        return true;
    }
};