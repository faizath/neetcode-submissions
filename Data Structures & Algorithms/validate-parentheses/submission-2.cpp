class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else {
                if (st.size() == 0) return false;
                switch(s[i]) {
                    case ')':
                        if (st.top() != '(') return false;
                        else st.pop();
                        break;
                    case ']':
                        if (st.top() != '[') return false;
                        else st.pop();
                        break;
                    case '}':
                        if (st.top() != '{') return false;
                        else st.pop();
                        break;
                    default: break;
                }
            }
        }
        return st.size() == 0;
    }
};
