class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1){
            vector<int> ans(1, 0);
            return ans;
        }
        vector<vector<int> > adj(n);
        int ed[n];
        for (int i = 0; i < n; i++)
            ed[i] = 0;
        for (auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            ed[i[0]]++; ed[i[1]]++;
        }
        set<int> leaf;
        for (int i = 0; i < n; i++)
            if (ed[i] == 1)
                leaf.insert(i);
        
        int rem = n;
        while(rem > 2){
            rem -= leaf.size();
            
            set<int> nleaf;
            for (int cur : leaf){
                ed[cur]--;
                for (int i : adj[cur]){
                    if (ed[i] > 1)
                        ed[i]--;
                    if (ed[i] == 1)
                        nleaf.insert(i);
                }
            }
            leaf = nleaf;
        }
        vector<int> ans;
        for(auto i : leaf)
            ans.push_back(i);
        return ans;
    }
};