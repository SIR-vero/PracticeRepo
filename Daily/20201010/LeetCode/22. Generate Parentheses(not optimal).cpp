class Solution {
private:
    bool checkParanthesis(const string& x)
    {
        int o = 0;
        for (auto i : x)
        {
            if (i == '(')
                o++;
            else if (o > 0)
                o--;
            else return false;
        }
        if (o == 0)
            return true;
        else 
            return false;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allPossible;
        int f = 0, check = 1;
        for (int f = 0; f < pow(2, 2*n); f++)
        {
            string a = "";
            for (int i = 0; i < 2*n; i++)
            {
                if ((f & (check << i)) == 0)
                    a+='(';
                else
                    a+=')';
            }
            allPossible.push_back(a);
        }
        vector<string> ans;
        for (auto a : allPossible)
        {
            cout << a << endl;
            if (checkParanthesis(a))
                ans.push_back(a);
        }
        return ans;
    }
};