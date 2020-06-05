class Solution {
public:
    std::discrete_distribution<> m_d;
    std::mt19937 m_gen;
    std::random_device m_rd;
    Solution(vector<int>& w):
        m_d(w.begin(),w.end()),
        m_rd(),
        m_gen(m_rd())
    {   
    }
    
    int pickIndex() {
        return m_d(m_gen);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */