class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> groups;
        for (int i = 0; i < groupSizes.size(); i++)
            groups[groupSizes[i]].push_back(i);
        
        vector<vector<int>> ans;
        for (auto i : groups)
        {
            for (int j = 0; j < i.second.size()/i.first; j++)
            {
                vector<int> temp;
                for (int k = (i.first)*j; k < (j+1)*i.first; k++)
                    temp.push_back(i.second[k]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};