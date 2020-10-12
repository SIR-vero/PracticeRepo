class Solution {
    
private:
    vector<int> ordering;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto i : prerequisites)
            adj[i[0]].push_back(i[1]);
        
        bool vis[numCourses];
        memset(vis, false, sizeof(vis));
        
        bool pos[numCourses];
        memset(pos, false, sizeof(pos));
        
        bool ans = true;
        
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
                ans = ans & dfs(i, vis, pos, adj);
        }
        if (ans)
            return ordering;
        vector<int> temp;
        return temp;
    }
    
    bool dfs(int curr, bool vis[], bool pos[], vector<vector<int>>& adj)
    {
        vis[curr] = true;
        if (adj[curr].size() == 0)
        {
            pos[curr] = true;
            ordering.push_back(curr);
            return true;
        }
        
        bool ans = true;
        
        for (int i : adj[curr])
        {
            if (vis[i] && !pos[i])
            {
                pos[curr] = false;
                return false;
            }
            else if (!vis[i])
                ans = ans & dfs(i, vis, pos, adj);
        }
        pos[curr] = ans;
        if (ans)
            ordering.push_back(curr);
        return ans;
    }
};