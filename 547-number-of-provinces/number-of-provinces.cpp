class Solution {
public:
    void dfst(int index,vector<int>& vis,vector<int> adj[]){
        for(int i = 0;i < adj[index].size();i++){
            if(!vis[adj[index][i]]){
                vis[adj[index][i]] = 1;
                dfst(adj[index][i],vis,adj);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> vis(n,0);
        vector<int> adj[n];

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i != j && isConnected[i][j] == 1)adj[i].push_back(j);
            }
        }

        int count = 0;

        for(int i = 0;i < n;i++){
            if(!vis[i]){
                count++;
                dfst(i,vis,adj);
            }
        }



        return count;
        
    }
};