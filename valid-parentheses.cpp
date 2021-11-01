class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (char c : s)
        {
            if (c=='(' || c=='{' || c=='[')
                stack.push(c);
            else
            {
                if (stack.empty()) return false;
                char reverse = stack.top();
                stack.pop();
                if (! ((reverse=='(' && c ==')') || (reverse=='{' && c=='}') || (reverse=='[' && c==']'))) return false;
            }
        }
        return stack.empty();
    }
};