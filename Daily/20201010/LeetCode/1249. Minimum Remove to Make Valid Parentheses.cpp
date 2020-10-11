class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (st.size())
                    st.pop();
                else
                    s[i] = '*';
            }
        }
        while(!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }
        string ans = "";
        for (auto i : s)
            if (i != '*')
                ans += i;
        return ans;
    }
};