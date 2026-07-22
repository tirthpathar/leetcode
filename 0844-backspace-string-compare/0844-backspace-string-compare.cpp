class Solution {
public:

    stack<char> buildStack(string s) {

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] != '#') {
                st.push(s[i]);
            }
            else {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        return st;
    }

    bool backspaceCompare(string s, string t) {

        stack<char> st1 = buildStack(s);
        stack<char> st2 = buildStack(t);

        if (st1.size() != st2.size())
            return false;

        while (!st1.empty()) {

            if (st1.top() != st2.top())
                return false;

            st1.pop();
            st2.pop();
        }

        return true;
    }
};