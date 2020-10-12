class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int s1x = 0,  s1y = 0;
        for (auto i : s1)
            if (i == 'x')
                s1x++;
            else 
                s1y++;
        int s2x = 0,  s2y = 0;
        for (auto i : s2)
            if (i == 'x')
                s2x++;
            else 
                s2y++;
        if (((s1x + s2x)%2 == 0) && ((s1y + s2y)%2 == 0))
        {
            int xy = 0, yx = 0;
            
            int ans = 0;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] == 'x' && s2[i] == 'y')
                    xy++;
                else if (s1[i] == 'y' && s2[i] == 'x')
                    yx++;
            }
            return (xy/2) + (yx/2) + (xy % 2 == 1 ? 2 : 0);
        }
        else 
            return -1;
    }
};